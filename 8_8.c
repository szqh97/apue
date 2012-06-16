/*
 * =======================================================================
 *       Filename:  8_8.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月10日 23时10分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <sys/wait.h>
char *env_init[] = {"USER=unknown", "PATH=/tmp",NULL};
int main ( int argc, char *argv[] )
{
    pid_t pid;
    if ((pid = fork()) < 0)
	err_sys("fork error!");
    else if(pid == 0)
    {
	if (execle("/usr/games/sl", "sl", (char*)0, env_init) < 0)
	    err_sys("execle error!");
    }
    if (waitpid(pid, NULL, 0) < 0)
    {
	err_sys("wait error!");
    }

   
    
    return 0;
}	/* ----------  end of function main  ---------- */


