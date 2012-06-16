#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>
int main()
{
    pid_t child;
    int status;
    printf("This will demostrate how to get child stauts\n");
    if ((child = fork()) == -1)
    {
	printf("Fork error: %s\n", strerror(errno));
	exit(1);
    }
    else if(child == 0)
    {
	int i;
	printf("I am the child: %d\n",getpid());
	for(i = 0; i<1000000; ++i)sin(i);
	i=5;
	printf("I exit whith %d\n",i);
	exit(1);
    }
    while(((child =wait(&status)) == -1)&(errno == EINTR));
    if(child ==-1)
	printf("Wait Error: %s\n",strerror(errno));
    else if(!status)
	printf("Child %d terminated normally return status is zero\n",child);
    else if(WIFEXITED(status))
	printf("Child %d terminated normally return staturs is %d\n",child, WEXITSTATUS(status));
    else if(WIFSIGNALED(status))
	printf("Child %d terminated due to signal %d znot caught\n", child, WTERMSIG(status));


}
