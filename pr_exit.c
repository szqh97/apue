/*
 * =======================================================================
 *       Filename:  pr_exit.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月08日 20时14分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <sys/wait.h>

void pr_exit(int status)
{
    
    if ( WIFEXITED(status))
	printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    else if ( WIFSIGNALED(status))
	printf("abnormal termination, signal number = %d%s\n", 
		WTERMSIG(status),
#ifdef WCOREDUMP
		WCOREDUMP(status) ? " (core file generated)" : "");
#else
	    "");
#endif
    else if (WIFSTOPPED(status))
	printf("child stopped , signal number = %d\n", WSTOPSIG(status));
}


