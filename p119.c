/*
 * =======================================================================
 *       Filename:  p119.c
 *    Description:  test fwrite
 *        Version:  1.0
 *        Created:  2012年04月04日 21时07分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#include <fcntl.h>
int main ( int argc, char *argv[] )
{
    float data[10] = {1, 2, 3.01, 4.5, 6.6, 3.45,6.7, 7};
    FILE *fp ;
    if ((fp = fopen ("test.txt", "wb")) == NULL)
	err_quit("open error!");
    if (fwrite(&data[2], sizeof(float), 4, fp) != 4)
	err_sys("fwrite error!");
    if(fclose(fp) != 0 )
	err_sys("close error!");
    return 0;
}	/* ----------  end of function main  ---------- */


