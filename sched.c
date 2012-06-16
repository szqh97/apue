/*
 * =======================================================================
 *       Filename:  sched.c
 *    Description:  test sched_..()
 *        Version:  1.0
 *        Created:  2012年04月22日 09时52分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <sched.h>

int main ( int argc, char *argv[] )
{
    int sche_no;
    pid_t pid;
    struct sched_param param;
    int result;
    if ((pid = getpid()) < 0)
	err_sys("get pid errror!");
    else
    {
	sche_no = sched_getscheduler(pid);
	printf("the sched id %d\n", sche_no);
    }

    result = sched_getparam(pid, &param);
    printf("the priority is %d\n", param.sched_priority);
    printf("the SCHED_NORMAL max is %d, min is %d\n", sched_get_priority_max(0), sched_get_priority_min(0));
    printf("the SCHED_FIFO max is %d, min is %d\n", sched_get_priority_max(1), sched_get_priority_min(2));
    return 0;
}	/* ----------  end of function main  ---------- */


