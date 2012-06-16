/*
 * =======================================================================
 *       Filename:  testsym.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月04日 09时58分47秒
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
    int re;
    
    if ((re = symlink("5_1.c", "5_1")) < 0)
	printf("create link error!");
    else
	printf ("create ok!");

    return 0;
}	/* ----------  end of function main  ---------- */


