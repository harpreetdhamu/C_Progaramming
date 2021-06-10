/* author - Vinay J
   organisation - Emertxe
   title - program to find and display average of 'n' subjects marks for 'm' students
   date - 15/05/2019 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 10

typedef struct student
{
	char *name;
	int *marks;
	float avg;
}student;

void populate (student *sptr,int *marks_array, int no_of_stud,int no_of_sub)
{

	/* populate the details for all the students */
	for (int i = 0 ; i < no_of_stud ; i++)
	{
		(sptr + i)->avg = 0;
	
		printf("Enter the student-%d details\n", i + 1);
		getchar();	
		printf("name : ");
		(sptr + i)->name = malloc(size * sizeof(char));
		scanf("%[a-z A-Z]", (sptr + i)->name);

		printf("marks : \n");
		for(int j = 0; j < no_of_sub; j++)
		{
			scanf("%d", &marks_array[j]);
			(sptr + i)->avg += marks_array[j];
		}
		(sptr + i)->marks = marks_array;
		marks_array = marks_array + no_of_sub; 
		(sptr + i)->avg /= no_of_sub;
	}
}

int main ()
{
	int no_of_stud, no_of_sub;
	float avg_of_n = 0;

	printf("Enter the number of students : ");
	scanf("%d", &no_of_stud);
	
	student stud_array[no_of_stud];

	printf("Enter the number of subjects : ");
	scanf("%d", &no_of_sub);

	int marks_array[no_of_stud * no_of_sub];
	
	populate (stud_array, marks_array, no_of_stud, no_of_sub);
		
	{	
		for (int i = 0; i < 16 + no_of_sub * 10 + 8; i++)
			printf("-");
		printf("\n");

		printf("S.no Name       ");	

		for (int i = 0; i < no_of_sub ; i++)
			printf("subject-%d ", i + 1);
		printf("Average\n");

		for (int i = 0; i < 16 + no_of_sub * 10 + 8; i++)
			printf("-");
		printf("\n");
		
		for (int i = 0 ; i < no_of_stud ; i++)
		{
			printf("%4d %-10s", i + 1, stud_array[i].name);
			for(int j = 0; j < no_of_sub; j++)
			{
				printf("%9d ", *(stud_array[i].marks + j));
			}
			printf("%8.2f\n", stud_array[i].avg);
		}

		for (int i = 0; i < 16 + no_of_sub * 10 + 8; i++)
			printf("-");
		printf("\n");

	}
	return 0;
}
