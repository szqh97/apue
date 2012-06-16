/*
 * =======================================================================
 *       Filename:  8_2.c
 *    Description:  test vfork
 *        Version:  1.0
 *        Created:  2012年04月08日 10时43分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
int glob = 6;

int main ( int argc, char *argv[] )
{
    int var;
    pid_t pid;
    var = 88;
    printf("before fork\n");
    if ((pid = vfork()) < 0)
	err_sys("fork error!");
    else if (pid == 0)
    {
	glob ++;
	var ++;
	//_exit(0);
	exit(0);
    }

    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    return 0;
}	/* ----------  end of function main  ---------- */


