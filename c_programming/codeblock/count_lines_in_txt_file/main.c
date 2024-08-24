#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pfile=NULL;
    int count;
    char temp;

    pfile=fopen("text.txt","r");
    if(pfile==NULL)
    {
        printf("could not open\n");
        return -1;
    }
    for(count=0;(temp=fgetc(pfile))!=EOF;)
    {
        if(temp=='\n')
        {
            count++;
        }
    }
    fclose(pfile);
    pfile=NULL;
    printf("Number of lines is %d",count+1);

    return 0;
}
