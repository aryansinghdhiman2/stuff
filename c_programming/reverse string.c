 #include <stdio.h>
//reverse string
int main()
{
    printf("Enter string of 10 elements\n");
    char s[11];
    int i,j=0;
    scanf(" ");
    for(i=0;i<10;i++)
    {
        scanf("%c",&s[i]);
    }
    s[10]='\0';
    char reverse[11];
    for(i=9,j=0;i>=0;i--,j++)
    {
        reverse[j]=s[i];
    }
    reverse[10]='\0';
    for(i=0;i<10;i++)
    {
        s[i]=reverse[i];
    }
    for(i=0;i<10;i++)
    {
        printf("%c",s[i]);
    }

    return 0;
}
