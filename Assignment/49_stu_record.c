#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
	char *name;
	int *marks;
	float average;
}student;
/*Function declaration*/
void scan(student *ptr,int *marks_arr,int num,int sub);
void print(student *ptr,int *marks_arr,int num,int sub);

/*Global variables*/
int num,sub,i,j;

int main()
{
	printf("Enter the number of student:\n");
	scanf("%d",&num);
	/*array number of student*/
	student n_stu[num];

	printf("Enter the number of subject:\n");
	scanf("%d",&sub);
	/*marks array*/
	int marks_arr[num * sub];

	/*pass the address of number of student array,marks array and pass by value of number of student,number of subject of both scan and print function*/
	scan(n_stu,marks_arr,num,sub);
	print(n_stu,marks_arr,num,sub);

}

/*scan the record of student in this function*/
void scan(student *ptr,int *marks_arr,int num,int sub)
{

	for(int i = 0;i < num; i++)
	{
		(ptr + i)->average = 0;

		printf("Enter the name[%d] of student%d:\n",i+1,i + 1);
		/*allocate the dynamically memory of name*/
		(ptr + i)->name = malloc(20 * sizeof(char));
		scanf("%s",(ptr + i)->name);
//		getchar();

		/*enter the marks of student*/
		printf("Enter the marks[%d] of student%d:\n",i+1,i + 1);
		for(j = 0;j < sub; j++)
		{
			printf("subject[%d] = ",j+1);
			scanf("%d",&marks_arr[j]);
			(ptr + i)->average += marks_arr[j];
		}

		/*calculate the marks of student and get a average*/
		(ptr + i)->marks = marks_arr;
		marks_arr = marks_arr + sub;
		(ptr + i)->average /= sub; 
		printf("\n");
	}

}

/*print the record of student in this function*/
void print(student *ptr,int *marks_arr,int num,int sub)
{
/*to print the ----- before printing the details of student record */
	for (i = 0; i < 16 + sub * 20 + 8; i++)
	{
		printf("-");
	}
	printf("\n");

	printf("S.no\tName\t  ");

	for ( i = 0; i < sub ; i++)
	{
		printf("Subject-%d\t ", i + 1);
	}
	printf("Average\n");

	for (i = 0; i < 16 + sub * 20 + 8; i++)
	{
		printf("-");
	}
	printf("\n");

	for(int i = 0;i < num; i++)
	{
		printf("%4d\t%-10s",i+1,(ptr + i)->name);

		for(j = 0;j < sub; j++)
		{
			printf("%9d\t",(ptr + i)->marks[j]);
		}
		printf("%8.2f\n", (ptr + i)->average);
	}
/*to print the ----- after printing the details of student record*/
	for (i = 0; i < 16 + sub * 20 + 8; i++)
	{
		printf("-");
	}
	printf("\n");

}
