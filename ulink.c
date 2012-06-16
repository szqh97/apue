//unlink int unlink( const char *pathname);
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main ( int argc, char *argv[] )
{
    int rs;
    if ( (rs = unlink ("ltl")) < 0)
    {
	printf("delet the link error!\n");
	exit(1);
    }
    return 0;
}	/* ----------  end of function main  ---------- */
