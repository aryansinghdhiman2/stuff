#include <stdio.h>
#include <stdlib.h>
int pstringlength(char const *pointer);
int main()
{
    int a;
    char str[100];
    printf("Enter string\n");
    scanf("%s",str);

    a=pstringlength(str);
    printf("\n%d",a);
    return 0;
}


int pstringlength(char const *pointer)
{
    char const *pointerLast=pointer;
    while(*pointerLast){
        pointerLast++;
    }
    return pointerLast-pointer;
}
