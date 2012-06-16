/*
 * =======================================================================
 *       Filename:  test1.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月27日 23时04分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"

int main ( int argc, char *argv[] )
{
    unsigned short i = 0;
    i |= (1<<2);
    printf("the value is %d\n", i);
    return 0;
}	/* ----------  end of function main  ---------- */


