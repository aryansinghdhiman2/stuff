#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    printf("\t\t\t1\n");
    printf("\t\t2\t\t3\n");
    printf("\t4\t\t5\t\t6\n");
    printf("7\t\t8\t\t9\t\t10\n");
    */

    int num=1,linecount=1,rowcount,check=1,count_2,temp;
    printf("Please enter the number of rows you want\n");
    scanf("%d",&rowcount);
    while(linecount<=rowcount)
    {
        temp=check;
        for(;check<rowcount;check++)
        {
            printf("\t");
        }
        for(count_2=0;count_2<linecount;num++,count_2++,printf("\t\t"))
        {
            printf("%d",num);
        }
        if(count_2==linecount)
        {
            printf("\n");
        }
        check=temp;
        check++;
        linecount++;
    }
    /*printf("Type anything to quit\n");
    scanf("%d",&count_2);*/

    return 0;
}
