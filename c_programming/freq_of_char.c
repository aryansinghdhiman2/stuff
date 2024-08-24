#include <stdio.h>

int main()
{
    int count;
    char str[100],x;
    printf("Enter string:");
    fgets(str,100,stdin);
    printf("Enter a character to find its freqency: ");
    scanf("%c",&x);
    for(int i=0;str[i]!='\0';i++)
    {
       if(x==str[i])
        count++;
    }
    printf("Freqency of character %c is %d",x,count);

    return 0;
}
