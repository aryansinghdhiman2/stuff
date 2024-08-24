#include <stdio.h>
#include <stddef.h>

int main()
{
    int number=15;
    int *pointer=NULL;
    pointer=&number;

    printf("The address of the pointer is %p\n",(void*)&pointer);
    printf("The pointer points to %p\n",pointer);
    printf("The value of the memory pointed by pointer is %d\n ",*pointer);
    return 0;
}
