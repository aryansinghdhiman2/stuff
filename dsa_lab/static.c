#include <stdio.h>

int main()
{
    static int x=5;
    printf("%d",x--);
    if(x)
        main();
}