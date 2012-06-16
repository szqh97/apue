/*
 * =======================================================================
 *       Filename:  testfread.c
 *    Description:  test fread 
 *        Version:  1.0
 *        Created:  2012年04月04日 21时27分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"

int main ( int argc, char *argv[] )
{
    float fp[5];
    int i;
    FILE * pfile;
    if ( (pfile = fopen("test.txt", "rb")) == NULL)
	err_quit("open the file error!");
    printf("the file id is %d\n", fileno(pfile));
    for ( i = 1; i <= 4; ++ i)
    {
	if ( fread(&fp[i], sizeof (float), 1, pfile) != 1)
	    err_quit("fread error");
	printf("the value is %f\n", fp[i]);
	printf("the position is %ld\n", ftell(pfile));
	fseek(pfile, 0, SEEK_SET);
    }
    if (fclose(pfile) !=0 )
	err_quit("file close !");
    return 0;
}	/* ----------  end of function main  ---------- */


