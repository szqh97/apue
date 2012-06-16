#include <stdio.h>
#include <unistd.h>
int main()
{
    char *str = get_current_dir_name();
    printf("%s\n",str);
    return 0;
}
