/*
 * =======================================================================
 *       Filename:  stack.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年05月13日 20时09分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <pthread.h>
void* fun()
{
    printf("thread 1 returning\n");
    return ((void*)1);
}

int main ( int argc, char *argv[] )
{
    int err;
    pthread_t tid;
    pthread_attr_t attr;
    size_t size;
    err = pthread_attr_init(&attr);
    err = pthread_attr_setstacksize(&attr, 10000);
    printf("the err = %d\n", err);
    err = pthread_create(&tid, &attr, fun, NULL);
    if (err != 0)
	err_quit("can't create thread!\n");
    err = pthread_attr_getstacksize(&attr, &size);
    printf("the stack size is %d\n", size);
    printf("the err = %d\n", err);
    err = pthread_attr_getstacksize(&attr, &size);
    printf("the err = %d\n", err);
    printf("the stack size is %d\n", size);
    err = pthread_getconcurrency();
    printf("the concurrency is %d\n", err);
    return 0;
}	/* ----------  end of function main  ---------- */


