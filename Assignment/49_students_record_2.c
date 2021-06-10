#include <stdio.h>
#include <stdlib.h>


struct student
{
	char name[32];
	int marks[8];
	float average;
};

int loop,name,mark,num,sub,count,n,m,i,j;
int main()
{
	printf("Enter the number of student:\n");
	scanf("%d",&num);
	struct student stu[num];
	//	struct	student *ptr = malloc(num * sizeof(struct student));
	printf("Enter the number of subject:\n");
	scanf("%d",&sub);
		for(int i = 0;i < num; i++)
		{
			printf("Enter the name[%d] of student%d:\n",n+1,n + 1);
			scanf("%s",stu[i].name);

			printf("Enter the marks[%d] of student%d:\n",n+1,n + 1);
			for(j = 0;j < sub; j++)
			{
				printf("subject[%d] = ",j+1);
				scanf("%d",&stu[i].marks[j]);
			}
			n++;
		}
		for(int i = 0;i < num; i++)
		{
			printf("Name of Student%d =  %10.10s\n",m+1,stu[i].name);

			printf("marks[%d] of student%d:\n",m+1,m + 1);
			for(j = 0;j < sub; j++)
			{
			printf("subject[%d] = %3d\n",j+1,stu[i].marks[j]);
			}
			m++;
		}
}
