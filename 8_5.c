/*
 * =======================================================================
 *       Filename:  8_5.c
 *    Description:  call fork two times to void zombie
 *        Version:  1.0
 *        Created:  2012年04月08日 21时34分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <sys/wait.h>

int main ( int argc, char *argv[] )
{
    pid_t pid;
    if ((pid = fork()) < 0)
	err_sys("fork error");
    else if (pid == 0)
    {
	if ((pid = fork()) < 0)
	    err_sys("fork error");
	else if (pid > 0)
	    exit (0);

	sleep (20);
	printf("second child, parent pid = %d\n", getppid());
	exit (0);
    }
    if (waitpid (pid, NULL, 0) != pid)
	err_sys("waitpid error!");
    return 0;
}	/* ----------  end of function main  ---------- */


