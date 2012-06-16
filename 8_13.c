/*
 * =======================================================================
 *       Filename:  8_13.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月11日 21时10分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <sys/wait.h>

int main ( int argc, char *argv[] )
{
    int status;
    if ((status = system("date")) < 0)
	err_sys("system() error");
    if ((status = system("who;exit 4")) < 0)
    {
	err_sys("system() error");
    }
    return 0;
}	/* ----------  end of function main  ---------- */


