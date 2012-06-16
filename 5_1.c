//using gets and putc to copy the standin into standout
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main ( int argc, char *argv[] )
{
    int c;
    while ((c = getc(stdin)) != EOF)
    {
	
	if (putc(c, stdout) == EOF)
	{
	    printf("output error\n");
	    exit(1);
	}
    }
    
    if (ferror(stdin))
    {
	printf("input error\n");
	exit(1);
    }
    return 0;
}	/* ----------  end of function main  ---------- */
