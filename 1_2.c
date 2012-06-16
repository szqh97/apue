/*
 * =======================================================================
 *       Filename:  1_2.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年01月31日 16时31分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 4096
int main()
{
    int n;
    char buf[SIZE];

    while ((n = read(STDIN_FILENO, buf, SIZE)) > 0)
    {
	if (write(STDOUT_FILENO, buf, n) != n )
	{
	    printf("write error!");
	    exit(1);
	}
    }
    if ( n < 0)
    {
	printf("read error");
	exit(1);
    }
    return 0;
}


