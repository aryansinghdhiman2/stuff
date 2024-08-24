#include <stdio.h>
//Uppercase
int main()
{
    char str[100];
    printf("Enter the string :\n");
    fgets(str,100,stdin);
    int i=0;
   while(str[i]!='\0') 
    {
        if(str[i]<=122 && str[i]>=97)
        {
            str[i]=str[i]-32;
        }
        i++;
    }
    printf("Uppercase string :\n%s",str);
    return 0;
}
