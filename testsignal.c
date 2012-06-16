/*
 * =======================================================================
 *       Filename:  testsignal.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年05月02日 22时11分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"

int main ( int argc, char *argv[] )
{
    printf("the sinal SIGINT is %s", strsignal(SIGINT));
    printf("the sinal SIGQUIT is %s", strsignal(SIGQUIT));
    return 0;
}	/* ----------  end of function main  ---------- */


