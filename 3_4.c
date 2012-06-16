/*
 * =======================================================================
 *       Filename:  3_4.c
 *    Description:  get the specific id
 *        Version:  1.0
 *        Created:  2012年04月03日 14时20分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <fcntl.h>

int main ( int argc, char *argv[] )
{
    int val;
    if (argc != 2)
	err_quit("usage: a.out <descriptor#>");
 
    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
	err_sys("fcntl error for fd %d", atoi(argv[1]));
    switch (val & O_ACCMODE)
    {
	
	case O_RDONLY:
	    printf("read only");
	    break;
	case O_WRONLY:
	    printf("write only");
	    break;
	case O_RDWR:
	    printf("read adn write");
	    break;
	default:
	    err_dump ("unkown access mode");
    }

    if (val & O_APPEND)
	printf(", append");
    if (val & O_NONBLOCK)
	printf(", nonblocking");


    return 0;
}	/* ----------  end of function main  ---------- */


