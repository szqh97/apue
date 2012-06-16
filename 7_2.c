/*
 * =======================================================================
 *       Filename:  7_2.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月07日 11时11分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"

static void my_exit1();
static void my_exit2();

int main ( int argc, char *argv[] )
{
    if (atexit(my_exit2) != 0)
	err_sys("can't register my_exit2");
    if (atexit(my_exit1) != 0)
	err_sys("can't register my_exit1");
    if (atexit(my_exit1) != 0)
	err_sys("can't register my_exit1");
    printf("main is done!");
    return 0;
}	/* ----------  end of function main  ---------- */

static void my_exit1()
{
    printf("first exit handler\n");
}

static void my_exit2()
{
    printf("seconed exit handler\n");
}
