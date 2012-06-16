#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define 	MAX 4069
int main()
{
    char buf[MAX];
    pid_t pid;
    int status;
    
    printf("%% ");
    while (fgets(buf, MAX, stdin) != NULL)
    {
	if (buf[strlen(buf) - 1] == '\n')
	    buf[strlen(buf) - 1] == 0; 
	if ((pid = fork()) < 0)
	{
	    printf("fork error!");
	    exit(1);
	}
	else if(pid == 0)
	{
	    execlp(buf, buf, (char *)0);
	    printf("couldn't execute: %s", buf);
	    exit(127);
	}
	if ((pid = waitpid(pid, &status, 0)) < 0)
	{
	    printf("waitpid error");
	    printf("%% ");
	}

    }
    return 0;
}
