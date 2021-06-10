/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Implement calc_mean for all data types 
Date:28-May-2019
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*function prototype*/
void scan_array(void *array,int size,int option);
int size,mean,sum,option,i,j;
char ch;
double sum1;

int main(int argc,char *argv[])
{
	do
	{
		 if (argc < 2)
         {
             printf("Error!!!! Alteast 2 numbers are entered\n");
             exit(1);
         }

		void *array;

		size = atoi(argv[1]);

		printf("Select the type of data\n1. Int\n2. short\n3. Float\n4. Double\nSelect a Option\n");
		scanf("%d",&option);
		switch (option)
		{
			case 1:
				array = malloc(sizeof(int) * size);
				/* Enter the Element of array */
				printf("Enter a Element of array:\n");
				scan_array(array,size,option);/*call the function to scanf the element of array and add the n numbers*/

				printf("sum = %d\nmean = %f\n",sum,sum/(float)size);
				printf("\n");
				break;
			case 2:
				array = malloc(sizeof(short) * size);
				/* Enter the Element of array */
				printf("Enter a Element of array:\n");
				scan_array(array,size,option);/*call the function to scanf the element of array and add the n numbers*/
				printf("sum = %hd\nmean = %f\n",(short)sum,sum/(float)size);
				break;
			case 3:
				array = malloc(sizeof(float) * size);
				/* Enter the Element of array */
				printf("Enter a Element of array:\n");
				scan_array(array,size,option);/*call the function to scanf the element of array and add the n numbers*/
				printf("sum = %f\nmean = %f\n",(float)sum1,sum1/(float)size);
				break;
			case 4:
				array = malloc(sizeof(double) * size);
				/* Enter the Element of array */
				printf("Enter a Element of array:\n");
				scan_array(array,size,option);/*call the function to scan the element of array and add the n numbers*/
				printf("sum = %lf\nmean = %f\n",sum1,sum1/(float)size);
				break;
			default:
				printf("You enter a Wrong Option\n");
				break;
		}
		sum = 0;
		printf("Do you want to continue (Y/N):\n");
		scanf("%s",&ch);
		if(ch == 'Y' || ch == 'y')
			continue;
		else if(ch == 'N' || ch == 'n')
			exit(1);
		else
		{
			printf("Wrong Input\n");
			exit(1);
		}
		free(array);
	}while(1);
	return 0;

}
/*function to scan the element of array and add the numbers*/
void scan_array(void *array,int size,int option)
{
	switch (option)
	{
		case 1:
			for(i=0;i<size;i++)
			{
				printf("array[%i] = ",i);
				scanf("%d",((int*)array + i));
				sum += *((int*)array + i);
			}
			printf("\n");
			break;
		case 2:

			for(i=0;i<size;i++)
			{
				printf("array[%i] = ",i);
				scanf("%hd",((short*)array + i));
				sum += *((short*)array + i);
			}
			printf("\n");

			break;
		case 3:
			for(i=0;i<size;i++)
			{
				printf("array[%i] = ",i);
				scanf("%f",((float*)array + i));
				sum1 += *((float*)array + i);
			}
			printf("\n");
			break;
		case 4:
			for(i=0;i<size;i++)
			{
				printf("array[%i] = ",i);
				scanf("%lf",((double*)array + i));
				sum1 += *((double*)array + i);
			}
			printf("\n");
			break;
		default:
			printf("You enter a Wrong Option\n");
			break;
	}
}

