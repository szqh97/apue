/*
 * =======================================================================
 *       Filename:  p142.c
 *    Description:  gethost
 *        Version:  1.0
 *        Created:  2012年04月07日 10时03分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <unistd.h>
#include <time.h>
int main ( int argc, char *argv[] )
{
    char pname[20];
    time_t tim;
    if ( gethostname(pname, 20) < 0)
	err_quit("error!");
    printf("the name is %s\n", pname);
    tim = time();
    printf("-->%ld\n", tim);

    return 0;
}	/* ----------  end of function main  ---------- */


