/*
 * =======================================================================
 *       Filename:  zmobie.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月08日 20时50分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main ( int argc, char *argv[] )
{
    pid_t pc, pr;
    int status;
    if ( (pc = fork()) < 0 )
	printf (" fork error!");
    else if (pc == 0)
    {
	printf("This is child process with pid of %d\n", getpid());
	exit (3);
    }
    else
    {
	pr = wait(&status);
	if (WIFEXITED(status))
	{
	    printf("The child process %d exit normally.\n", pr);
	    printf("The WEXITSTATUS retusn code is %d\n", WEXITSTATUS(status));
	    printf("The WIFEXITED return code is %d\n", WIFEXITED(status));
	}
	else 
	    printf("The child process %d exit abnormally.\n", pr);
    }
    return 0;
}	/* ----------  end of function main  ---------- */


