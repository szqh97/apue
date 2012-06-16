#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#define MAXSIZE 4096
static void sig_int(int);

int main()
{
    char buf[MAXSIZE];
    pid_t pid;
    int status;
    if(signal (SIGINT, sig_int) == SIG_ERR)
    {
	printf("signal error\n");
	exit(1);
    }
    printf("%% ");
    while(fgets(buf, MAXSIZE, stdin) != NULL)
    {
	if(buf[strlen(buf) - 1] == '\n')
	    buf[strlen(buf) - 1] = 0;
	if((pid = fork()) < 0)
	{
	    printf("fork error!");
	    exit(1);
	}
	else if(pid ==0)
	{
	    execlp(buf, buf, (char*)0);
	    printf("couldn`t execute: %s\n",buf);
	    exit(127);
	}
	if((pid = waitpid(pid, &status, 0)) < 0)
	{
	    printf("waitpid error\n");
	    exit(1);

	}
	printf("%% ");

    }
    exit(0);
}

void sig_int(int signo)
{
    printf("interrupt \n%%");
}
