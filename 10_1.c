/*
 * =======================================================================
 *       Filename:  10_1.c
 *    Description:  test signal
 *        Version:  1.0
 *        Created:  2012年04月25日 23时07分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
static void sig_usr(int);

int main ( int argc, char *argv[] )
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
	err_sys("can't catch SIGUSR1");
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
	err_sys("can't catch SIGUSR2");
    for( ; ; )
	pause();
    
    return 0;
}	/* ----------  end of function main  ---------- */

static void sig_usr(int signo)
{
    if (signo == SIGUSR1)
	printf("received SIGUSR1\n");
    else if (signo == SIGUSR2)
	printf("received SIGUSR2\n");
    else
	printf("reveived signo %d\n", signo);
}
