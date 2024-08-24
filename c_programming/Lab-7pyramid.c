#include <stdio.h>
int main()
{
    int num=1,linecount=1,rowcount=5,count,inc_dec=1,temp;
	int whitespace=2*rowcount-1;
    while(linecount<=rowcount)
    {
        for(temp=whitespace;temp!=0;temp--)
        {
            printf(" ");
        }
        whitespace=whitespace-2;
        for(count=0,num=linecount,inc_dec=1;count<2*(linecount)-1;count++,num=num+inc_dec)
        {
            if(num>=(2*(linecount)-1))
                {
                    inc_dec=-inc_dec;
                }
            printf("%d ",num);
        }
        printf("\n");
        linecount++;
    }
    return 0;
}
