//the example to function utime()
//int utime (const char *pathname, const struct utimbuf *times)
//struct utimbuf {
//	time_t actime;
//	time_t modtime;
//}
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <utime.h>
#include <sys/stat.h>
#include <sys/types.h>
int main ( int argc, char *argv[] )
{
    int i, fd;
    struct stat statbuf;
    struct utimbuf timebuf;
    
    for (i = 1; i < argc ; ++i)
    {
	
	if (stat(argv[i], &statbuf) < 0)
	{// fetch current times
	    printf("%s: stat error\n", argv[i]);
	    continue;
	}
	
	if ( (fd = open(argv[i], O_RDWR | O_TRUNC) < 0))
	{
	    //truncate
	    printf("%s: open error\n", argv[i]);
	    continue;
	}
	close (fd);
	timebuf.actime = statbuf.st_atime;
	timebuf.modtime = statbuf.st_mtime;
	
	if ( utime(argv[i], &timebuf) < 0)
	{
	    printf("%s: utime error\n", argv[i]);
	    continue;
	}

    }
    return 0;
}	/* ----------  end of function main  ---------- */
