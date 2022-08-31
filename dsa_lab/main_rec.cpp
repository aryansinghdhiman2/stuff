#include<cstdio>

int main()
{
    static int d = 5;
    if(--d)
    {
        main();
        printf("%d",d);
    }
}