#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    printf("hello world form process ID %d\n", getpid());
    return 0;
}

