/*
 * =======================================================================
 *       Filename:  testc.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月26日 21时08分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
static void catch(int );
int main ( int argc, char *argv[] )
{
    signal(SIGINT, catch);
    printf("hello!\n");
    sleep(10);
    return 0;
}	/* ----------  end of function main  ---------- */

static void catch(int sig)
{
    printf("heheheh\n");
}
