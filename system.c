/*
 * =======================================================================
 *       Filename:  system.c
 *    Description:  system.c without version
 *        Version:  1.0
 *        Created:  2012年04月11日 21时04分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
int system(const char *cmdstring)
{
    pid_t pid;
    int status;

    if (cmdstring == NULL)
	return 1;
    if ((pid = fork()) < 0)
    {
	status = -1;
    }
    else if (pid == 0)
    {
	execl("/bin/sh", "sh", "-c", cmdstring, (char*)0);
	_exit(127);
    }
    else
    {
	while(waitpid(pid, &status, 0) < 0)
	{
	    if (errno != EINTR)
	    {
		status = -1;
		break;
	    }
	}
    }
    return status;
}

