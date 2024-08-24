#include <stdio.h>

int main()
{
    int c,a,b,add,s,m;
    float d;
    printf("Operations:\n");
    printf("1:Addition\n");
    printf("2:Subtraction\n");
    printf("3:Multiplication\n");
    printf("4:Division\n");
    printf("Enter the number associated to the operation\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:printf("Enter two numbers for addition:\n");
               scanf("%d %d",&a,&b);
               add=a+b;
               printf("Addition:%d",add);
               break;
        case 2:printf("Enter two numbers for subtraction:\n");
               scanf("%d %d",&a,&b);
               s=a-b;
               printf("Subtraction:%d",s);
               break;
        case 3:printf("Enter two numbers for multiplication:\n");
               scanf("%d %d",&a,&b);
               m=a*b;
               printf("Multiplication:%d",m);
               break;
        case 4:printf("Enter two numbers for division:\n");
               scanf("%d %d",&a,&b);
               d=(float)a/b;
               printf("Division:%.2f",d);
               break;
        default:printf("Please enter something else");
    }
    return 0;
}