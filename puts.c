
#include <stdio.h>
#include <stdlib.h>
int main()
{
    if (puts("hello word!\n") < 0 )
    {
	printf("puts error!\n");
	exit(0);
    }
    return 0;
}
