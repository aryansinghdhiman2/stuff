#include <stdio.h>
#include <stdlib.h>

int main()
{
    float time,overTime,grossPay,tax,netPay;

    printf("Enter time worked: ");
    scanf("%f", &time);

    if(time>40)
    {
        overTime= time-40;
    }
    else
    {
        overTime=0;
    }
    if(time<40){
        grossPay= time*12;
    }
    else {
        grossPay=40*12 +(overTime*18);
    }
    if(grossPay<=300)
    {
        tax=300*15/100;
    }
    else if(grossPay>300 && grossPay<=450){
        tax= 300*15/100 + (grossPay-300)*20/100;
    }
    else if(grossPay>450){
        tax= 300*15/100 + 150*20/100 +(grossPay-450)*25/100;
    }
    netPay= grossPay-tax;

    printf("Gross Pay is %f\n", grossPay);
    printf("Tax is %f\n", tax);
    printf("Net Pay is %f\n", netPay);
    printf("Overtime is %f\n", overTime);



    return 0;
}
