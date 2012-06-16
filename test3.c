#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_SIZE 1024
int main(int argc, char **argv)
{
    int from_fd, to_fd;
    int bytes_read, bytes_write;
    char buffer[BUFFER_SIZE];
    char *ptr;
    if(argc != 3)
    {
	fprintf(stderr,"Usage: %s fromfile to file\n\a",argv[0]);
	exit(1);
    }
    if((from_fd = open(argv[1], O_RDONLY)) == -1)
    {
	fpintf(stderr, "Open %s Error: %s\n",argv[1], strerror(errno));
	exit(1);
    }

}
