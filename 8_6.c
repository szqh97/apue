/*
 * =======================================================================
 *       Filename:  8_6.c
 *    Description:  test race condition
 *        Version:  1.0
 *        Created:  2012年04月09日 23时25分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
static void charatatime(char *);

int main ( int argc, char *argv[] )
{
    pid_t pid;
    if ((pid = fork()) < 0)
	err_sys("fork errror!");
    else if (pid == 0)
	charatatime("output from child\n");
    else
	charatatime("output from parent\n");
	
    return 0;
}	/* ----------  end of function main  ---------- */

static void charatatime(char *str)
{
    char *ptr;
    int c;
    setbuf(stdout, NULL);
    for (ptr = str; (c = *ptr++) != 0; )
	putc(c, stdout);
}
