/*
 * =======================================================================
 *       Filename:  11_3.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年05月05日 21时40分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <pthread.h>

struct foo
{
    int a, b ,c, d;
};

void printfoo(const char *s, const struct foo* fp)
{
    printf("%s",s);
    printf(" structure at 0x%x\n", (unsigned)fp);
    printf(" foo.a = %d\n", fp->a);
    printf(" foo.b = %d\n", fp->b);
    printf(" foo.c = %d\n", fp->c);
    printf(" foo.d = %d\n", fp->d);
}

void * thr_fn1(void *arg)
{
    struct foo foo ={1, 2, 3, 4};
    printfoo("thread 1:\n", &foo);
}


void * thr_fn2(void *arg)
{
    printf("thread 2 ID is %d\n", (int)pthread_self());
    pthread_exit((void *)0);
}

int main ( int argc, char *argv[] )
{
    int err;
    pthread_t tid1, tid2;
    struct foo *fp;
    size_t size;
    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0)
	err_quit("can't create thread 1\n");
    err = pthread_attr_getstacksize(&tid1, &size);
    printf("the stack size if %d\n", size);
    err = pthread_join(tid1, (void * )&fp);
    if (err != 0)
	err_quit("can't join with thread 1\n");
    sleep(1);
    printf("parent starting second thred\n");
    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0)
	err_quit("can't create thread 2\n");
    sleep(1);
    printfoo("parent:\n", fp);

    return 0;
}	/* ----------  end of function main  ---------- */
