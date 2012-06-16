/*
 * =======================================================================
 *       Filename:  env.c
 *    Description:  test getenv
 *        Version:  1.0
 *        Created:  2012年04月07日 15时44分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <stdlib.h>

int main ( int argc, char *argv[] )
{
    char *path;
    path = getenv("PATH");
    printf("PATH is %s\n", path);
    return 0;
}	/* ----------  end of function main  ---------- */


