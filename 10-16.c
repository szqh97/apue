/*
 * =======================================================================
 *       Filename:  10-16.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年05月02日 20时14分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"

volatile sig_atomic_t quitflag;	//set nonzero by signal handler

static void sig_int (int signo)
{
    if (signo == SIGINT)
	printf("/ninterrupt");
    else if (signo == SIGQUIT)
	quitflag = 1;	//set flag for main loop
}

int main ( int argc, char *argv[] )
{
    sigset_t newmask, oldmask, zeromask;
    if (signal(SIGINT, sig_int) == SIG_ERR)
	err_sys("signal(SIGINT) error!");
    if (signal(SIGQUIT, sig_int) == SIG_ERR)
	err_sys("signal(SIGQUIT) error!");
    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    
    // block SIGQOUT and save current signal mask.
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
	err_sys("sigprocmask eror");
    while (quitflag == 0)
	sigsuspend(&zeromask);

    //SIGQUIT has been caught adn is now blocked ; wo whatever
    quitflag = 0;

    //reset signal mask which unblocks SIGQUIT.
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
	err_sys ("SIG_SETMASK erro!");
    return 0;
}	/* ----------  end of function main  ---------- */


