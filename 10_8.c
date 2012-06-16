/*
 * =======================================================================
 *       Filename:  10_8.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月27日 22时03分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <setjmp.h>

static void sig_alarm(int);
static jmp_buf env_alarm;

int main ( int argc, char *argv[] )
{
    int n;
    char line[MAXLINE];

    if (signal(SIGALRM, sig_alarm) == SIG_ERR)
	err_sys("signal SIGALRM err!");
    if (setjmp(env_alarm) != 0)
	err_quit("read timeout!");
    alarm (3);
    if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
	err_sys("read err!");
    alarm (0);
    write(STDOUT_FILENO, line, n);
    
    return 0;
}	/* ----------  end of function main  ---------- */

static void sig_alarm(int signo)
{
    longjmp(env_alarm, 1);
}

