#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

static int get_file_size_time(const char *filename)
{
    struct stat statbuf;
    if(stat(filename, &statbuf) == -1)
    {
	printf("Get stat on %s Error: %s \n", filename, strerror(errno));
	return -1;
    }
    if(S_ISDIR(statbuf.st_mode)) return 1;
    if(S_ISREG(statbuf.st_mode)) 
    {
	printf ("%s size: %d bytes \tmodified at %s", filename, statbuf.st_size, ctime(&statbuf.st_mtime));
    }
    return 0;
}

int main(int argc, char **argv)
{
    DIR *dirp;
    struct dirent *direntp;
    int stats;
    if(argc != 2)
    {
	printf("Usage: %s filename\n\a", argv[0]);
	exit(1);
    }
    if((stats = get_file_size_time(argv[1])) ==0 || (stats ==-1)) exit(1);
    if((dirp = opendir(argv[1])) == NULL)
    {
	printf("Open Director %s Error: %s\n", argv[1], strerror(errno));
	exit(1);
    }
    while((direntp = readdir(dirp)) != NULL)
    {if(get_file_size_time(direntp<d_name) == -1) break;
    close(dirp);
    exit(1)}

    return 0;
}


