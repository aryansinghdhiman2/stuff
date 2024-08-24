#include <stdio.h>

int main()
{
    float totalSellingPrice,totalProfit,costPrice;
	printf("Please enter Total Selling Price \n");
	scanf("%f", &totalSellingPrice);
	printf("Please enter Total Profit \n");
	scanf("%f",&costPrice);
    costPrice=(totalSellingPrice-totalProfit)/15;
    printf("\nCost price is %.3f",costPrice);

    return 0;
}
