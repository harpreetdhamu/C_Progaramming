#include <stdio.h>
#include <stdlib.h>

int avg, a, b;

struct student
{
	char name[100];
	int  marks[100];
	float avg;
}student;


void get_record(struct student *p, int *m, int *n)
{
	for(int i = 0; i < *m; i++)
	{
		printf("Enter name of the student : ");
		scanf("%s", p->name);

		printf("Enter the marks for each subjects : ");
		for(int j = 0; j < *n; j++)
		{
			scanf("%d", p->marks);
			p++;
		}
		p++;
	}
	printf("\n");
}

void display_record(struct student *p, int *m, int *n)
{
	printf("---------------------------------------------------------\n");
	printf("Name\t\tMaths\t\tPhysics\t\tChemistry\n");
	printf("---------------------------------------------------------\n");

	for(int i = 0; i < *m; i++)
	{
		printf("%s\t", p->name);
		for(int j = 0; j < *n; j++)
		{
			printf("\t%2d\t", *p->marks);
			p++;
		}
		printf("\n");
		p++;
	}
}

int main()
{
	int m, n;

	printf("Enter the number of students: ");
	scanf("%d", &m);

	struct student std[m];

	//struct student *p = malloc (m * sizeof(struct student));

	printf("Enter the number of subjects: ");
	scanf("%d", &n);

	get_record (std, &m, &n);
	display_record (std, &m, &n);

	printf("---------------------------------------------------------\n");
	printf("Average\t");

	for(int i = 0; i < n; i++)
	{
		printf("\t%.2f\t", ((float)(*(std+i)->marks) + (float)(*(std+i+n+1)->marks))/m);
	}

	printf("\n---------------------------------------------------------\n");
}
