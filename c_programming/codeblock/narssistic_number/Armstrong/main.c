#include <stdio.h>
#include <math.h>
int main()
{
    int number,externalCounter,remain,sum=0,dummyNumber,tempNumber2=1,digitCounter;

    for(externalCounter=0;externalCounter!=100000;++externalCounter,sum=0)
   {
        number=externalCounter+1;
        for(tempNumber2=1,digitCounter=0;tempNumber2!=0;)
        {
            tempNumber2=number/10;
            number=number/10;
            digitCounter++;
        }
        number=externalCounter+1;
        dummyNumber=number;
        while(number)
        {
            remain=number%10;
            sum=sum+(pow(remain,digitCounter));
            number=number/10;
        }
        if(dummyNumber==sum){
            printf("%d is an Armstrong Number\n",dummyNumber);
        }
    }
    return 0;
}
