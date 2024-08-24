#include <stdio.h>
#include <stdlib.h>



int gdc(int x,int y)
{
    if(x<y)
    {
        int c=0;
        c=y;
        y=x;
        x=c;
    }
    int b;
    for(b=1;b!=0;x=y,y=b)
    {
        b=x%y;
        if(b==0)
        {
            return y;
        }
}
 return 0;
}
int main()
{
    int k,l;
    printf("Enter the number for which you want greatest common divisior\n");
    scanf("%d%d", &k,&l);
    printf("GCD is %d", gdc(k,l));
    return 0;
}
