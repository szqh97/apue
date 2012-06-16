/*
 * =======================================================================
 *       Filename:  testexecl.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月11日 21时01分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */

#include <unistd.h>

int main ( int argc, char *argv[] )
{
    execl("/bin/ls","ls", "-al", "/etc/passwd", NULL);

    return 0;
}	/* ----------  end of function main  ---------- */

