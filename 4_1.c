/*
 * =====================================================================================
 *
 *       Filename:  4_1.c
 *
 *    Description:  对每个文件参数进行打印文件类型
 *
 *        Version:  1.0
 *        Created:  2011年08月21日 22时17分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

    int
main ( int argc, char *argv[] )
{
    int i;
    struct stat buf;
    char *ptr;

    
    for ( i = 1; i < argc; ++i )
    {

	printf ( "%s: ", argv[i] );
	if ( lstat(argv[i], &buf) < 0 )
	{
	    printf ( "lstat error\n" );
	    exit(1);
	    continue;
	}
	if ( S_ISREG(buf.st_mode))
	    ptr = "regular";
	else if ( S_ISDIR(buf.st_mode))
	    ptr = "directory";
	else if ( S_ISLNK(buf.st_mode))
	    ptr = "link";
	else if ( S_ISBLK(buf.st_mode))
	    ptr = "block ";
	else if ( S_ISFIFO(buf.st_mode))
	    ptr = "fifo";
	else if ( S_ISSOCK(buf.st_mode))
	    ptr = "socket";
	printf ("%s\n", ptr);
    }
    return 0;
}				/* ----------  end of function main  ---------- */
