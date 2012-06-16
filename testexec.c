/*
 * =======================================================================
 *       Filename:  testexec.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月11日 20时32分20秒
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
	err_sys("fork error!");
    else if (pid == 0)
    {
	if (execl("a.out","a.out",(char *)0) < 0)
	    err_sys("execl error");

    }
    if (waitpid(pid, NULL, 0) < 0)
	err_sys("waitpid error");
    return 0;
}	/* ----------  end of function main  ---------- */


