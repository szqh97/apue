/*
 * =======================================================================
 *       Filename:  4_4.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月03日 21时38分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
int main ( int argc, char *argv[] )
{
    struct stat statbuf;

    if (stat("foo", &statbuf) < 0)
	err_sys("stat error for foo");
    if (chmod("foo", (statbuf.st_mode & ~S_IXGRP)|S_ISGID) < 0)
	err_sys("chmod error for foo");
    if (chmod("bar", S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH) < 0 )
	err_sys("chomd error");
    return 0;
}	/* ----------  end of function main  ---------- */


