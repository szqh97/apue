/*
 * =======================================================================
 *       Filename:  testalarm.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月26日 20时55分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
static void sig_alarm(int );

int main ( int argc, char *argv[] )
{
    alarm (0);

    pause();
    printf("test ....");
    return 0;
}	/* ----------  end of function main  ---------- */

static void sig_alarm(int signo)
{
    printf("get the SIGALARM is %d\n", signo);
}

