/*
 * =======================================================================
 *       Filename:  8_4.c
 *    Description:  display different exit id
 *        Version:  1.0
 *        Created:  2012年04月08日 20时21分03秒
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
    pid_t pid;
    int status;

    if ((pid = fork()) < 0)
	err_sys("fork error");
    else if (pid == 0)
	exit (7);
    if (wait (&status) != pid)
	err_sys("wait error!");
    pr_exit(status);

    if ((pid = fork()) < 0)
	err_sys("for error2!");
    else if (pid == 0)
	abort();

   if ( wait(&status) != pid)
       err_sys("wait error 2 !");
   pr_exit(status);
   
   if ((pid = fork()) < 0)
       err_sys("for error 3!");
   else if (pid == 0)
       status /= 0;

  if (wait (&status) != pid)
      err_sys("wait error3!");
  pr_exit(status);

    return 0;
}	/* ----------  end of function main  ---------- */

