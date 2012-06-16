/*
 * =======================================================================
 *       Filename:  10_14.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月29日 11时42分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <setjmp.h>
#include <time.h>
static void sig_usr1(int);
static void sig_alarm(int);
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjmp;

int main ( int argc, char *argv[] )
{
    if (signal(SIGUSR1, sig_usr1) == SIG_ERR)
	err_sys("signal(SIGUSR1) error!");
    if (signal(SIGALRM, sig_alarm) == SIG_ERR)
	err_sys("signal(SIGALEM) error!");
    pr_mask("starting main:");

    if (sigsetjmp(jmpbuf, 1))
    {
	pr_mask("ending main:");
	exit(0);
    }
    canjmp = 1;
    for(;;)
	pause();
}	/* ----------  end of function main  ---------- */

static void sig_usr1(int signo)
{
    time_t starttime;
    
    if (canjmp == 0)
    {
	return ;
    }
    pr_mask("starting sig_usr1");
    alarm (5);
    starttime = time(NULL);
    for (;;)
	if(time(NULL) > starttime + 5)
	    break;
    pr_mask("finishing sig_usr1");
    canjmp = 0;
    siglongjmp(jmpbuf, 1);
}
static void sig_alarm(int signo)
{
    pr_mask("in sig_alarm:");
}
