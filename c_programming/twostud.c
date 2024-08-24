#include<stdio.h>

struct students{
		char name[25];
		int roll;
		float mark;
	};

int main()
{
	struct students stud[2];
	printf("Enter student information:\n");
	for(int i=0;i<2;i++)
	{
	    printf("Enter Roll Number:");
	    scanf("%d",&stud[i].roll);
	    printf("Enter Name:");
	    scanf("%s",stud[i].name);
	    printf("Enter Marks:");
	    scanf("%f",&stud[i].mark);
	}
	
	printf("\nDisplaying information\n");
	for(int i=0;i<2;i++)
	{
	    printf("Roll Number: %d\n",stud[i].roll);
	    printf("Name of Student: %s\n",stud[i].name);
	    printf("Marks of Student: %f\n",stud[i].mark);
	}
	
	return 0;
}