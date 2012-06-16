/*
 * =======================================================================
 *       Filename:  5_5.c
 *    Description:  test tempnam
 *        Version:  1.0
 *        Created:  2012年04月06日 21时36分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
int main ( int argc, char *argv[] )
{
    if (argc != 3)
	err_quit("usage: a.out <dirctory> <prefix>");
    printf("%s\n", tempnam(argv[1][0] != ' ' ? argv[1]:NULL, argv[2][0] != ' ' ? argv[2] : NULL));
    return 0;
}	/* ----------  end of function main  ---------- */


