/*
 * =======================================================================
 *       Filename:  pr_mask.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月28日 22时20分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <errno.h>

void pr_mask(const char *str)
{
    sigset_t sigset;
    int errno_save;
    errno_save = errno;
    if (sigprocmask(0, NULL, &sigset) < 0)
	err_sys("sigprocmask error");
    printf("%s\n", str);
    
    if (sigismember(&sigset, SIGINT)) printf("SIGINT");
    if (sigismember(&sigset, SIGQUIT)) printf("SIGQUIT");
    if (sigismember(&sigset, SIGUSR1)) printf("SIGUSR1");
    if (sigismember(&sigset, SIGALRM)) printf("SIGALRM");

    printf("\n");
    errno = errno_save;
}


