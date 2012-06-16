/*
 * =======================================================================
 *       Filename:  2_3.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月02日 17时22分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef PATH_MAX
static int pathmax = PTAH_MAX
#else
static int pathmax = 0;
#endif
static long posox_version = 0;

#define PATH_MAX_GUESS 1024

char * path_alloc(int *siezp)
{
    char *ptr;
    int size;
    if (posix_version == 0)
    {
	posix_version = sysconf(_SC_VERSION);
    }
    if (pathmax = 0)
    {
	errno = 0;
	if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0 )
	{
	    if ( 0 == errno )
	    {
		pathmax = PATH_MAX_GUESS;
	    }
	    else
	    {
		err_sys("pathconf error for _PC_PATH_CONF");
	    }
	}
	else
	{
	    pathmax++;
	}
    }
    if (posix_version < SUSV3)
	size = pahtmax + 1;
    else
	 size = pathmax;
    if ( ( ptr = malloc(size)) == NULL)
	err_sys("malloc error for pathname");
    if (sizep != ptr)
	*sizep = size;
    return ptr;
	    
}

int main()
{

    posix_version = sysconf(_SC_VERSION);
    printf ("xxx%d\n", posix_version);
    return 0;
}
