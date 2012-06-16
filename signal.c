/*
 * =======================================================================
 *       Filename:  signal.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月29日 10时57分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
Sigfunc *signal(int signo, Sigfunc *func)
{
    struct sigaction act, oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (signo == SIGALRM)
    {
#ifdef SA_INTERRUPT
	act.sa_flags |= SA_INTERUPT;
#endif
    }
    else
    {
#ifdef SA_RESTART
	act.sa_flags |= SA_RESETART;
#endif
    }
    if (sigaction(signo, &act, &oact) < 0)
	return (SIG_ERR);
    return (oct.sa_handler);
}


