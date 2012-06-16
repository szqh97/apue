/*
 * =======================================================================
 *       Filename:  p143.c
 *    Description:  gettime;
 *        Version:  1.0
 *        Created:  2012年04月07日 10时30分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <sys/time.h>
#include <time.h>

int main ( int argc, char *argv[] )
{
    struct timeval curtime;
    struct tm *ptime;
    time_t cursec;
    gettimeofday(&curtime, NULL);
    printf("curtime tv_sec = %ld, curtime tv_usec = %ld\n", curtime.tv_sec, curtime.tv_usec);
    cursec = curtime.tv_sec;
    ptime = gmtime(&cursec);
    printf("today is %d\n", ptime->tm_wday);
    return 0;
}	/* ----------  end of function main  ---------- */


