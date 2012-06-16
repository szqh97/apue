#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main ( int argc, char *argv[] )
{
    if (chdir ("/home/szqh97/a") < 0)
    {
	printf ("chdir failed\n");
	exit(1);
    }
    printf("chdir t /home/szqh97/example/a succeeeded\n");
    return 0;
}	/* ----------  end of function main  ---------- */
