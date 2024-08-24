#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1=NULL;
    FILE *f2=NULL;

    f1=fopen("source.txt","r");
    if(f1==NULL)
    {
        printf("An error occurred\n");
        return 0;
    }
    f2=fopen("destination.txt","w");
    if(f2==NULL)
    {
        printf("An error occurred\n");
        return 0;
    }
    char x;
    for(;;)
    {
        x=fgetc(f1);
        if(x==EOF)
        {
            break;
        }
        fputc(x,f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
