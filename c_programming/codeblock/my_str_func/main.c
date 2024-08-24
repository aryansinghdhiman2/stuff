#include <stdio.h>
#include <stdlib.h>

void my_str_cpy(char* d,const char* const s);

int main()
{
    char str[]="Hello";
    printf("%s",str);
    char another[]=" World";
    my_str_cpy(str,another);
    printf("%s",str);
    return 0;
}

void my_str_cpy(char* destination,const char* const source)
{
    if(destination==NULL)
        return;
    if(source==NULL){
        destination=NULL;
        return;
    }
    int src_len=0,des_len=0;
    for(src_len=0;source[src_len]!='\0';src_len++);

    for(des_len=0;destination[des_len]!='\0';des_len++);

    int len=0;
    if(src_len>des_len)
        len=des_len;
    else
        len=src_len;
    for(int i=0;i<len;i++)
    {
        destination[i]=source[i];
    }
    destination[len]='\0';
}
