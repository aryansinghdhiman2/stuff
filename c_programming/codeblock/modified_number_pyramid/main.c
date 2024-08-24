#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    printf("       1\n");
    printf("     2 3 2\n");
    printf("   3 4 5 4 3\n");
    printf(" 4 5 6 7 6 5 4\n");
    */

    int num=1,linecount=1,rowcount,whitespacecheck=1,count_2,maxval,inc_dec=1,temp;
    printf("Please enter the number of rows you want\n");
    scanf("%d",&rowcount);
    whitespacecheck=rowcount+(rowcount-1);
    while(linecount<=rowcount)
    {
        for(temp=whitespacecheck;temp!=0;temp--)
        {
            printf(" ");
        }
        whitespacecheck=whitespacecheck-2;
       maxval=linecount-1;
        for(count_2=0,num=linecount,inc_dec=1;count_2<linecount+maxval;count_2++,num=num+inc_dec)
        {
            if(num>=linecount+maxval)
                {
                    inc_dec=-inc_dec;
                }
            printf("%d",num);
            printf(" ");
        }
        if(count_2==linecount+maxval)
        {
            printf("\n");
        }
        linecount++;
    }
    /*printf("Type anything to quit\n");
    scanf("%d",&count_2);*/
    return 0;
}
