#include <stdio.h>

int main()
{
    int marks[5];
    int aggregrateMarks=0,percentage;
    int i;
    
    printf("Enter the marks of the student\n");
    scanf("%d", &marks[0]);
	scanf("%d", &marks[1]);
	scanf("%d", &marks[2]);
	scanf("%d", &marks[3]);
	scanf("%d", &marks[4]);
	
	aggregrateMarks= marks[0]+marks[1]+marks[2]+marks[3]+marks[4];
	
    percentage=aggregrateMarks*100/500;
    
    printf("Aggregrate marks are %d\n", aggregrateMarks);
    printf("Percentage marks are %d\n", percentage);
    return 0;
}