#include<cstdio>

int incr(int x)
{
    static int count;
    count=count+x;
    return count;
}
int main()
{
    int i,j;
    for(i=0;i<=4;i++)
    {
        j=incr(i);
    }
    printf("%d",j);
}