/*
 * =======================================================================
 *       Filename:  3-3.c
 *    Description:  put thngs from stdin put stdout
 *        Version:  1.0
 *        Created:  2012年04月03日 11时32分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#define	BUFFSIZE 4096			/*  */

int main ( int argc, char *argv[] )
{
    int n;
    char buf[BUFFSIZE];

    
    while ( (n = read (STDIN_FILENO, buf, BUFFSIZE)) > 0)
	if (write(STDOUT_FILENO, buf, n) != n)
	    err_sys("write error");

    if (n < 0)
	err_sys("read error!");

    return 0;
}	/* ----------  end of function main  ---------- */


