#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
	char name[32];
	int marks[10];
	float average[10];
}student;

void scan(student *ptr,int num,int sub);
void print(student *ptr,int num,int sub);
int num,sub,i,j;
int main()
{
	printf("Enter the number of student:\n");
	scanf("%d",&num);
	student *ptr = (student*)malloc(num * sizeof(student));
	printf("Enter the number of subject:\n");
	scanf("%d",&sub);
	scan(ptr,num,sub);
	print(ptr,num,sub);
#if 0
	for(int i = 0;i < num; i++)
	{
		printf("Enter the name[%d] of student%d:\n",i+1,i + 1);
		scanf("%s",(ptr + i)->name);

		printf("Enter the marks[%d] of student%d:\n",i+1,i + 1);
		for(j = 0;j < sub; j++)
		{
			printf("subject[%d] = ",j+1);
			scanf("%d",&(ptr + j)->marks[i]);
		}
		printf("\n");

	}
	printf("---------------------------------------------------------------------\n");
	printf("S.no\tStudent Name\tSubject\tmarks\t\n");
	printf("---------------------------------------------------------------------\n");
	for(int i = 0;i < num; i++)
	{
		printf("%2d\t%10.10s\t",i+1,(ptr + i)->name);

		for(j = 0;j < sub; j++)
		{
			printf("\t%2d\t",(ptr + j)->marks[i]);
		}
		printf("\n");
	}
	printf("---------------------------------------------------------------------\n");
#endif
}
void scan(student *ptr,int num,int sub)
{

	for(int i = 0;i < num; i++)
	{
		printf("Enter the name[%d] of student%d:\n",i+1,i + 1);
		scanf("%s",(ptr + i)->name);

		printf("Enter the marks[%d] of student%d:\n",i+1,i + 1);
		for(j = 0;j < sub; j++)
		{
			printf("subject[%d] = ",j+1);
			scanf("%d",&(ptr + j)->marks[i]);
		}
		printf("\n");
	}

}
void print(student *ptr,int num,int sub)
{
	printf("---------------------------------------------------------------------\n");
	printf("S.no\tStudent Name\t\tSubject1\tSubject2\tAverage\t\n");
	printf("---------------------------------------------------------------------\n");
	for(int i = 0;i < num; i++)
	{
		printf("%2d\t%10.10s\t",i+1,(ptr + i)->name);

		for(j = 0;j < sub; j++)
		{
			printf("\t%2d\t",(ptr + j)->marks[i]);
		}
		printf("\n");
	}
	printf("---------------------------------------------------------------------\n");
	for(i= 0;i < sub; i++)
	{
		(ptr + i)->average[i] = (ptr + i)->marks[i] + (ptr + i + 1)->marks[i]; 
		printf("\t%g\t\n",(ptr + i)->average[i]);
	}

}
