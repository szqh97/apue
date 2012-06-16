/*
 * =======================================================================
 *       Filename:  10_22.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年05月02日 21时44分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#define BUFFSIZE 1024
static void sig_tstp(int);

int main ( int argc, char *argv[] )
{
    int n;
    char buf[BUFFSIZE];
    /*
     * only cathc SIGTSP if we're running with a job control shell
     */
    if(signal(SIGTSTP, SIG_IGN) == SIG_DFL)
	signal(SIGTSTP, sig_tstp);
    while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	if (write(STDOUT_FILENO, buf, n) != n)
	    err_sys("write error!");
    if (n < 0)
	err_sys("read error!");
    return 0;
}	/* ----------  end of function main  ---------- */
static void sig_tstp(int signo)
{
    sigset_t mask;
    
    /* move cursor to lower left corner reset tty mode 
     * unblock SIGTSTP, since it's blocked while we're handling it.
     */
    sigemptyset(&mask);
    sigaddset(&mask, SIGTSTP);
    sigprocmask(SIG_UNBLOCK, &mask, NULL);
    signal(SIGTSTP, SIG_DFL); // reset diposition to default 
    kill(getpid(), SIGTSTP); //and send the signal to ourself

    signal(SIGTSTP, sig_tstp);
}

