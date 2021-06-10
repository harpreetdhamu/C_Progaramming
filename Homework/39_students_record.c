#include <stdio.h>
#include <stdlib.h>


struct student
{
	char name[2][32];
	int marks[3][20];
	float average;
}record;

int main()
{

	char array[2][32];
	int name,mark,num,sub,count = 2,n = 0,i =0;
		printf("Enter the number of student:\n");
		scanf("%d",&num);

	//	struct	student *ptr = malloc(num * sizeof(struct student));
	//	printf("Enter the number of subject:\n");
	//	scanf("%d",&sub);
	if(0 < count)
	{
		printf("Enter the name[%d] of student%d:\n",i+1,n + 1);
		for(int i = 0;i < 1; i++)
		{
			scanf("%s",record.name[i]);
		}
		printf("Enter the marks[%d] of student%d:\n",i+1,n + 1);
		for(int i = 0;i < 3; i++)
		{
			scanf("%d",record.marks[i]);
		}
		count++;
		n++;
	}
}
