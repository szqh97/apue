// open a file and unlink it
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main ( int argc, char *argv[] )
{
    int fd;
    if ((fd = open ("ltl", O_RDWR)) < 0 )
    {
	printf("open error!\n");
	exit(1);
    }
    else
    {
	printf("file open success!\n");
    }
    if (close (fd) < 0 )
    {
	printf("close file error!\n");
	exit(1);
    }
    else
	printf("file close success!\n");

    if (unlink("ltl") < 0 )
    {
	printf("unlink error!\n");
	exit(1);
    }
    printf ("file unlinked!\n");
    sleep(15);
    printf("done!\n");
    return 0;
}	/* ----------  end of function main  ---------- */
