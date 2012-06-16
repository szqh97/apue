/*
 * =======================================================================
 *       Filename:  10_11.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月28日 22时48分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"

static void sig_quit(int );


int main ( int argc, char *argv[] )
{
    sigset_t newmask, oldmask,pendmask;
    if (signal(SIGQUIT, sig_quit) == SIG_ERR)
	err_sys("can't catch SIGQUIT");

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
	err_sys("SIG_BLOCK error");
    sleep(5);
    if (sigpending(&pendmask) < 0)
	err_sys("sigpending err!");
    if (sigismember (&pendmask, SIGQUIT) )
	printf("\nSIGQUIT pending\n");

    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
	err_sys("SIG_SETMASK error");
    printf("SIGQUIT ublocked\n");
    sleep(5);

    return 0;
}	/* ----------  end of function main  ---------- */
static void sig_quit(int signo)
{
    printf("caught SIGQUIT\n");
    if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
	err_sys("can't reset SIGQUIT");
}

