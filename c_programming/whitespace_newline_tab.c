#include <stdio.h>

int main()
{
    char j,temp;
    int count_1=0,count_2=0,count_3=0;
    printf("Please enter character\n");
    for(;;)
    {
        scanf("%c",&j);
        if(j!='\n')
            scanf("%c",&temp);
        if(j=='1')
            break;
        switch(j)
        {
            case' ':
                count_1++;
                break;
            case'\t':
                count_2++;
                break;
            case'\n':
                count_3++;
                break;
            
        }
    }
    printf("The number of whitespaces are %d\n",count_1);
    printf("The number of tabs are %d\n",count_2);
    printf("The number of newlines are %d\n",count_3);

    return 0;
}
