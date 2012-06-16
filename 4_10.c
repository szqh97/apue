/*
 * =======================================================================
 *       Filename:  4_10.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月04日 10时52分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#ifdef SOLARIS
#include <sys/mkdev.h>
#endif

int main ( int argc, char *argv[] )
{
    int i;
    struct stat buf;
    for (i = 1;i < argc;++i)
    {
	printf ("%s ", argv[i]);
	if (stat(argv[i], &buf) < 0)
	{
	    err_ret("stat error");
	    continue;
	}
	printf ("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));
	if (S_ISCHR(buf.st_mode)||S_ISBLK(buf.st_mode))
	{
	    printf(" (%s) rdev = %d/%d", S_ISCHR(buf.st_mode) ? "character": "block", major (buf.st_rdev), minor(buf.st_rdev));
	    
	}
    printf("\n");
    }
    return 0;
}	/* ----------  end of function main  ---------- */


