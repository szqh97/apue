/*
 * =======================================================================
 *       Filename:  5_4.c
 *    Description:  test tmpnam, tmpfile
 *        Version:  1.0
 *        Created:  2012年04月06日 21时28分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"

int main ( int argc, char *argv[] )
{
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;
    printf("%s\n", tmpnam(NULL));
    printf("%s\n", name);
    tmpnam(name);
    printf("%s\n", name);

    if((fp = tmpfile()) == NULL)
	err_sys("tmpflie error!");
    fputs("one line .....\n", fp);
    rewind (fp);
    if (fgets(line, sizeof(line), fp) == NULL)
	err_sys("fgets error!");
    fputs(line, stdout);
    return 0;
}	/* ----------  end of function main  ---------- */


