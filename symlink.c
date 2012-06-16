//int symlink (const char *actualpath, const char *sympath)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main ( int argc, char *argv[] )
{
    int rs;
    if ((rs = symlink ("link.c", "ltl.c")) < 0 )
    {
	printf ("symlink error\n");
	exit(1);
    }
    else
    {
	printf ("create symbol link\n");
    }
    return 0;
}	/* ----------  end of function main  ---------- */
