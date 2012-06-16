/*
 * =======================================================================
 *       Filename:  8_1.c
 *    Description:  fork()
 *        Version:  1.0
 *        Created:  2012年04月08日 08时50分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"

int glob = 6;
char buf[] = "a write to stdout\n";

int main ( int argc, char *argv[] )
{
    int var;
    pid_t pid;
    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf) - 1)
	err_sys("write error");
    printf("before fork()\n");		// we don't flus stdout

    if ((pid = fork()) < 0)
	err_sys("fork error");
    else if (pid == 0)			//child 
    {					//modify variables
	glob++;
	var++;
    }
    else
	sleep(2);			//parent

    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    return 0;
}	/* ----------  end of function main  ---------- */


