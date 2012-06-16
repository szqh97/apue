/*
 * =======================================================================
 *       Filename:  2_2.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月02日 16时18分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */

#include "apue.h"
#include <errno.h>
#include <limits.h>
static void pr_sysconf(char *, int);
static void pr_pathconf(char *, char *, int);
int main(int argc, char *argv[])
{
    if (2 != argc)
    {
	err_quit ("usage a.out <dirname>");
    }
#ifdef ARG_MAX
    printf("ARG_MAX defined to be %d\n", ARG_MAX + 0);
#else
    printf("no symbol for ARG_MAX\n");
#endif

#ifdef MAX_CON 
    printf("MAX_CON defined to be %d\n", MAX_CON + 0);
#else
    printf("no symbol for MAX_CON\n");
#endif

#ifdef _PC_ARG_MAX
    printf("_PC_ARG_MAX defined to be %d\n", _PC_ARG_MAX + 0);
#else
    printf("no symbol for ARG_MAX\n");
#endif

return 0;

}

static void pr_sysconf (char *mesg, int name)
{
    long var;
    fputs (mesg, stdout);
    errno = 0;
    if ((var = sysconf(name)) < 0)
    {
	if ( errno != 0 )
	{
	    if ( EINVAL == errno )
	    {
		fputs(" (no supported )\n",stdout);
	    }
	    else
	    {
		err_sys("sysconf error");
	    }
	}
	else
	{
	    fputs ("(no limits)\n", stdout);
	}
    }
    else
    {
	printf(" %ld \n", var);
    }

}

static void pr_pathcofn(char *mesg, char *pathname, int name)
{
    long var;
    fputs (mesg, stdout);
    errno = 0;
    if ((var = pathconf(pathname, name)) < 0)
    {
	if ( errno != 0)
	{
	    if ( EINVAL == errno )
	    {
		fputs (" (not supported)\n", stdout);
	    }
	    else
	    {
		err_sys("pathconf error, path = %s", pathname);
	    }
	}
	else
	{
	    fputs (" (no limit)\n", stdout);
	}
    }
    else
    {
	printf(" %ld\n", var);
    }
}
