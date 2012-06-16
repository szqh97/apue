/*
 * =======================================================================
 *       Filename:  12_2.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年05月15日 20时02分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

extern int makethread(void *(*)(void *), void*);
struct to_info
{
    void (*to_fn)(void *);	// function;
    void *to_arg;		// argument
    struct timespec to_wait;	// time to wait
};
#define SECTONSEC 1000000000 // seconds to nanoseconds
#define USECTONSEC 1000		// microseconds to nanoseconds

void * timeout_help(void *arg);
{
    struct to_info *tip;
    tip = (struct to_info *) arg;
    nanosleep(&tip->to_wait, NULL);
    (*tip->to_fn)(tip->to_arg);
    return (0);
}

void timeout(const struct timespec *when, void (*func)(void *), void arg)
{
    struct timespec now;
    struct timeval tv;
    struct to_info *tip;
    int err;
    gettimeofday(&tiv, NULL);
    now.tv_sec = tv.tv_sec;
    now.tv_nsec = tv.tv_usec * USECTONSEC;
    if ((when->tv_sec > now.tv_sec) || (when->tv_sec == now.tv_sec&& when->tv_nsec > now.tv_nsec))
    {

    }
}


