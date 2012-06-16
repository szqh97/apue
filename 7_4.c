/*
 * =======================================================================
 *       Filename:  7_4.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2012年04月07日 16时27分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  szqh97 (), szqh97@163.com
 *        Company:  szqh97
 * =======================================================================
 */
#include "apue.h"
#define TOK_ADD 5

void do_line (char *);
void cmd_add ();
int get_token();

int main ( int argc, char *argv[] )
{
    char line[MAXLINE];
    while ( fgets(line, MAXLINE, stdin) != NULL)
	do_line(line);

    return 0;
}	/* ----------  end of function main  ---------- */

char *tok_ptr;

void do_line (char *ptr)
{
    int cmd;
    tok_ptr = ptr;
    while ((cmd = get_token()) > 0)
    {
	switch (cmd)
	{
	    case TOK_ADD:
		cmd_add();
		break;
	}
    }
}

void cmd_add()
{
    int token;
    token = get_token();
}

int get_token()
{
    return 3;
}
