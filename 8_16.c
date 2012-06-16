/*
 * =======================================================================
 *       Filename:  8_16.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月11日 22时22分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"

int main ( int argc, char *argv[] )
{
    pid_t pid;
    if ((pid = fork()) < 0) 
	err_sys("fork error!");
    else if(pid != 0)
    {
	sleep(2);
	exit (2);
    }
    printf("the parent process\n");

    if ((pid = fork()) < 0)
	err_sys("fork error!");
    else if (pid != 0)
    {
	sleep (4);
	printf("the first process\n");
	abort();
    }

    if ((pid = fork()) < 0)
	err_sys("fork error!");
    else if (pid != 0)
    {
	execl("/bin/echo", "cat", "test.c", NULL);
	exit(7);
    }
    printf("the second process\n");

    if ((pid = fork()) < 0)
	err_sys("fork error");
    else if (pid != 0)
    {
	sleep(2);
	printf("the third process\n");
	exit(0);
    }

    sleep(3);
    printf("the four process\n");
    kill(getpid(), SIGKILL);
    exit(6);
    return 0;
}	/* ----------  end of function main  ---------- */


