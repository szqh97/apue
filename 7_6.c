/*
 * =======================================================================
 *       Filename:  7_6.c
 *    Description:  longjmp
 *        Version:  1.0
 *        Created:  2012年04月07日 19时40分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <setjmp.h>

static void f1 (int, int, int, int);
static void f2 ();
static jmp_buf jmpbuffer;
static int globval;

int main ( int argc, char *argv[] )
{
    int autoval;
    register int regival;
    volatile int volaval;
    static int statval;
    globval = 1; autoval = 2; regival = 3; volaval= 4; statval = 5;
    if (setjmp(jmpbuffer) != 0)
    {
	printf("after longjmp:\n");
	printf("globval = %d, autoval = %d, regival = %d, volaval = %d, staval = %d\n", globval, autoval, regival, volaval, statval);

	exit(0);
    }
    globval = 95; autoval = 96; regival = 97;volaval= 97;statval = 99;
    
    f1(autoval, regival, volaval, statval);
    return 0;
}	/* ----------  end of function main  ---------- */

static void f1(int i, int j, int k, int l)
{
    printf("in f1():\n");
    printf("globval = %d, autoval = %d, regival = %d, volaval = %d, staval = %d\n", globval, i, j, k, l);
    f2();
}

static void f2()
{
    longjmp(jmpbuffer, 1);
}

