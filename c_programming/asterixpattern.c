
#include <stdio.h>

int main()
{
    int i,line;
    for(line=1;line<=4;line++)
    {
        for(i=0;i<line;i++)
            printf("*");
        printf("\n");
    }

    return 0;
}
