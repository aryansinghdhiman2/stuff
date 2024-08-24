#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char* argv[])
{
    for(int i=0;i<argc;i++)
    {
        int conv=atoi(argv[i]);
        if(!conv)
        {
            printf("%s ",argv[i]);
        }
        else
        {
            printf("%d ",conv);
        }
        
    }
}