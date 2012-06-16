/*
 * =======================================================================
 *       Filename:  4_3.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月03日 21时09分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <fcntl.h>
#define	RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
int main ( int argc, char *argv[] )
{
    umask(0);
    
    if (creat("foo", RWRWRW) < 0)
	err_sys("create error!");
    umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if (creat("bar", RWRWRW) < 0)
	err_sys("create error!");
    return 0;
}	/* ----------  end of function main  ---------- */


