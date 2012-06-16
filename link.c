//int link(const char *existingpath, const char *newpath);
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main ( int argc, char *argv[] )
{
    const char *oldname = "link.c";
    int result;
    if ((result = link (oldname, "ltl")) == -1)
    {
	printf("create the link error!\n");
	exit(1);
    }
    return 0;
}	/* ----------  end of function main  ---------- */
