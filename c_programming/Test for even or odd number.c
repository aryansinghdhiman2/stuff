#include <stdio.h>

int main() {
    int number, remain;
    printf("Enter the number\n");
    scanf("%d", &number);
    
    remain= number%2;
    if(remain==0) {
        printf("Your number is even\n" );
    }
    else {
        printf("Your number is odd\n" );
    }
    return 0;
}