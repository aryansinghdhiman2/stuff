#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void longest_out_of_five(char**);
int main()
{
    char** name_list;
    name_list=calloc(5,sizeof(char*));
    
    int k;
    for(k=0;k<5;k++)
    {
        *(name_list+k)=calloc(15,sizeof(char));
        scanf("%s",*(name_list+k));
    }
    longest_out_of_five(name_list);
    free(name_list);

    return 0;
}

void longest_out_of_five(char** a)
{
    char temp[15];
    strcpy(temp,a[0]);
    for(int i=0;i<=3;i++)
    {
        if(strlen(a[i+1])>strlen(temp))
        {
            strcpy(temp,a[i+1]);
        }
    }
    printf("The longest name is %s",temp);
}
