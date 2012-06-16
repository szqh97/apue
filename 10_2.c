/*
 * =======================================================================
 *       Filename:  10_2.c
 *    Description:  j
 *        Version:  1.0
 *        Created:  2012年04月26日 20时16分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <pwd.h>
static void my_alarm( int signo)
{
    struct passwd *rootptr;
    printf("in signal handler\n");
    if ((rootptr = getpwnam("root")) == NULL)
	err_sys("getpwnam err!");
    alarm(1);
}
int main ( int argc, char *argv[] )
{
    struct passwd *ptr;
    signal(SIGALRM, my_alarm);
    alarm (1);
    for (; ; )
    {
	if ((ptr = getpwnam("szqh97")) == NULL)
	    err_sys("getpwnam err!");
	if (strcmp(ptr->pw_name, "szqh97") != 0)
	    printf(" return value corrupted!, pw_name = %s\n", ptr->pw_name);
    }

    return 0;
}	/* ----------  end of function main  ---------- */


