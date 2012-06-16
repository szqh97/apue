/*
 * =======================================================================
 *       Filename:  testjmp.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月26日 22时18分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include <iostream>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
jmp_buf jmpbuffer;

void g()
{
    cout << "in g()" << endl;
    longjmp(jmpbuffer, 2);
}

void f()
{
    cout << "in f() " << endl;
    g();
    cout << "leave f()" << endl;
}

int globval;


int main ( int argc, char *argv[] )
{
    int autoval;
    register int regival;
    volatile int volaval;
    static int statval;
    cout << "begin" << endl;
    
    globval = 90;
    autoval = 91;
    regival = 92;
    volaval = 93;
    statval = 94;

    int i = setjmp(jmpbuffer);
    
    cout << "setjmpbuffer return code: " << i << endl;

    if (i == 2)
    {
	cout << "error code: " << 1 << endl;

	cout << "globval = " << globval << ";";
	cout << "autoval = " << autoval << ";";
	cout << "regival = " << regival << ";";
	cout << "volaval = " << volaval << ";";
	cout << "statval = " << statval << ";"<< endl;
	return 0;
    }
    
    globval = 0;
    autoval = 1;
    regival = 2;
    volaval = 3;
    statval = 4;

    cout << "globval = " << globval << ";";
    cout << "autoval = " << autoval << ";";
    cout << "regival = " << regival << ";";
    cout << "volaval = " << volaval << ";";
    cout << "statval = " << statval << ";"<< endl;

    f();
    return 0;
}	/* ----------  end of function main  ---------- */
