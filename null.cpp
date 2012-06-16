/*
 * =======================================================================
 *       Filename:  null.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月29日 10时01分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */

#include <iostream>
using namespace std;
class A
{
    public:
	void fun()
	{
	    cout << "function A" << endl;
	}
};

int main ( int argc, char *argv[] )
{
    A *pa ;
    pa = NULL;
    pa->fun();

    return 0;
}	/* ----------  end of function main  ---------- */
