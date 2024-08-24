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

    grossPay= time*12 + (overTime*18);

    if(grossPay < 300)
    {
        tax= 0;
    }
    else if(grossPay >= 300 && grossPay < 450)
    {
        tax= (15/100)*300;
    }
    else if(grossPay == 450)
    {
        tax= ((15/100)*300)+(150*(20/100));
    }
    else if(grossPay > 450)
    {
        tax= ((15/100)*300)+(150*(20/100))+(grossPay-450)*(25/100);
    }
    netPay= grossPay-tax;

    printf("Gross Pay is %f\n", grossPay);
    printf("Tax is %f\n", tax);
    printf("Net Pay is %f\n", netPay);
    printf("overtime is %f\n", overTime);



    return 0;
}
