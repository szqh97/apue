/*
 * =======================================================================
 *       Filename:  11_2.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年05月05日 21时16分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <pthread.h>
void* thr_fn1(void *arg)
{
    printf("hrread 1 returning\n");
    return ((void *)1);
}

void* thr_fn2(void *arg)
{
    printf("hrread 2 exiting\n");
    pthread_exit ((void *)2);
}

int main ( int argc, char *argv[] )
{
    int err;
    pthread_t tid1, tid2;
    void *tret;
    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0)
	err_quit("can't crete thread 1: %s\n", strerror(err));

    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0)
	err_quit("can't crete thread 2: %s\n", strerror(err));
    err = pthread_join(tid1, &tret);
    if (err != 0)
	err_quit("thread 1 exit code %d\n", strerror(err));
    printf("thread 1 exit code %d\n", (int)tret);
    err = pthread_join(tid2, &tret);
    if (err != 0)
	err_quit("thread 2 exit code %d\n", strerror(err));
    printf("thread 2 exit code %d\n", (int)tret);
    return 0;
}	/* ----------  end of function main  ---------- */
