/*
 * =======================================================================
 *       Filename:  10_15.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年05月02日 19时41分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"

static void sig_int(int);

int main ( int argc, char *argv[] )
{
    sigset_t newmask, oldmask, waitmask;
    pr_mask("program start:");
    if (signal(SIGINT, sig_int) == SIG_ERR)
	err_sys("signal(SIGINT) error");
    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);
    sigemptyset(&newmask);
    sigaddset(&newmask,SIGINT);
    
    //block SIGINT and save current signal mask.
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
	err_sys("sigprocmask error!");
    
    // critical region of code.
    
    pr_mask("in critiacl region: ");

    //pause allowing all signlas except SIGUSR1

    if (sigsuspend(&waitmask) != -1)
	err_sys("sigsuspend error!");
    pr_mask("after return from sigsuspend: ");
    // reset signal mask which unblocks SIGINT.
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
	err_sys("SIG_SETMASK erroR!");

    // and continuse processing ...
    pr_mask("program exit:" );
    return 0;
}	/* ----------  end of function main  ---------- */
static void sig_int(int signo)

{
    pr_mask("\nin sig_int: ");
}

