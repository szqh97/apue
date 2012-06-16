/*
 * =======================================================================
 *       Filename:  3_2.c
 *    Description:  create a file contain a hole
 *        Version:  1.0
 *        Created:  2012年04月03日 10时19分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */

#include "apue.h"
#include <fcntl.h>
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main ( int argc, char *argv[] )
{
    int fd;

    if ( (fd = creat("file.nohole", FILE_MODE)) < 0)
	err_sys ("create error");
    
    if (write (fd, buf1, 10) != 10)
	err_sys ("lseek error");
    //if (lseek (fd, 16384, SEEK_SET) == -1)
	err_sys("lseek error");
    if (write (fd, buf2, 10) != 10)
	err_sys("buf2 write error!");
    return 0;
}	/* ----------  end of function main  ---------- */


