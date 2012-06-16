/*
 * =======================================================================
 *       Filename:  getsid.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月16日 22时31分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <unistd.h>

int main ( int argc, char *argv[] )
{
    pid_t pid;
    if ((pid = getsid(1)) < 0)
	err_sys("getsid error!");
    printf("the session pid is %d\n", pid);
    return 0;
}	/* ----------  end of function main  ---------- */


