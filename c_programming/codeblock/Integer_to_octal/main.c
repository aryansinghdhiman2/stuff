#include <stdio.h>
#include <stdlib.h>
int main()
{
    const int base=8;
    int tempNumber,digitCounter,number,dummyNumber,i,k,resetNumber;
    printf("Please enter integer you want converted: ");
    scanf("%d",&number);
    printf("\n\n");
    resetNumber=number;
    for(tempNumber=1,digitCounter=0;tempNumber!=0;)
        {
            tempNumber=number/10;
            number=number/10;
            digitCounter++;
        }
        number=resetNumber;
        int storeNumber[digitCounter+1];
        for(i=0;;i++)
        {
            dummyNumber=number/base;
            storeNumber[i]=number%base;
            number=dummyNumber;
            if(number<base)
            {
                storeNumber[i+1]=dummyNumber;
                break;
            }
        }
        for(k=digitCounter;k>=0;k--)
        {
            printf("%d",storeNumber[k]);
        }

    return 0;
}
