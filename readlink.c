// ssize_t readlink (const char * restrict pathname, char *restrict buf, size_t bufsize)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main ( int argc, char *argv[] )
{
    char buf[20];
    int bs;	//the size of buffer;

    if ( (bs = readlink ("ltl.c", buf, sizeof(buf))) < 0)
    {
	printf("readlink error!\n");
	exit(1);
    }
    else
    {
	printf("%s\n", buf);
    }
    return 0;
}	/* ----------  end of function main  ---------- */
