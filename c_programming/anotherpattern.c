
#include <stdio.h>

int main()
{
    int i,line,num,white=3,temp;
    for(line=1,num=1;line<=4;line++,num++)
    {
        for(temp=white;temp!=0;temp--)
        {
            printf(" ");
        }
        white--;
        for(i=0;i<line;i++)
            printf("%d ",num);
        printf("\n");
    }

    return 0;
}
