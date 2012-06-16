/*
 * =======================================================================
 *       Filename:  4_2.c
 *    Description:  test access function
 *        Version:  1.0
 *        Created:  2012年04月03日 20时49分41秒
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
    
    if (argc != 2)
	err_quit("usage a.out <pathname>");
    if (access(argv[1], R_OK))
    {
	printf ("read access ok");
    }
    else
    {
	printf("can not read !");
    }
    if (open(argv[1], O_RDONLY) < 0)
	printf("open error!");
    else
	printf("open for reading!");
    return 0;
}	/* ----------  end of function main  ---------- */


