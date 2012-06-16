/*
 * =======================================================================
 *       Filename:  p135.c
 *    Description:  get infomation from /et/passwd 
 *        Version:  1.0
 *        Created:  2012年04月07日 09时12分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <pwd.h>

int main ( int argc, char *argv[] )
{
    struct passwd *pt ;
    if ((pt = getpwnam("szqh97")) != NULL )
    {
	printf("the name is %s\n", pt->pw_name);
	printf("the uid is %d\n", pt->pw_uid);
    }
    return 0;
}	/* ----------  end of function main  ---------- */


