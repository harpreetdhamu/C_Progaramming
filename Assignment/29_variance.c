/*
   Author Name: Chanchal Parkash
   organization name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Variance calculation with static arrays & with dynamic arrays
Date:10-june-2019
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*variance prototype*/
void variance(int *array,int size);
int main()
{
	int option,size,i,*str;
	char ch;
	do
	{	
		printf("Select a array\n1. Static arrays\n2. Dynamic arrays\nSelect a option\n");
		scanf("%d",&option);
		switch (option)
		{
			case 1:
				{
					printf("Enter the size of array:\n");
					scanf("%d",&size);
					int array[size];
					for(i = 0;i < size;i++)
					{
						printf("array[%i] = ",i);
						scanf("%d",&array[i]);
					}
					/* pass the array address and size to function variance*/
					variance(array,size);
				}
				break;
			case 2:
				{
					printf("Enter the size of array:\n");
					scanf("%d",&size);
					/* Allocate the memory dynamically*/
					str = malloc(size);
					for(i = 0;i < size;i++)
					{
						printf("array[%i] = ",i);
						scanf("%d",(str + i));
					}
					/* pass the array address and size to function variance*/
					variance(str,size);
				}
				break;
			default:
				printf("Wrong Input\n");
				break;
		}

		printf("Do you want to continue(y/n)\n");
		scanf("%s",&ch);
/*		if (ch == 'Y' || ch == 'y')
		{
			continue;
		}
		else if (ch == 'N' || ch == 'n')
		{
			exit(1);
		}
		else
		{
			printf("Wrong input\n");
			exit(1);
		}*/
	}while(ch == 'y'|| ch == 'Y');
}
/* Function variance */
void variance(int *array,int size)
{
	int i,sum = 0,mean = 0,temp = 0;
	float sigma = 0;

	for(i = 0;i < size;i++)
	{
		sum = sum + array[i];
	}
	/* mean is calculated by Mean = (sum of x) / size*/
	mean = sum / size;

	for(i = 0;i < size;i++)
	{
		array[i] = mean - array[i];
		array[i] = array[i] * array[i];
		temp = temp + array[i];
	}
/*Formula to calulate the variance:sigma = (sum of D 2 ) / size*/
	sigma = temp /(float)size;
	printf("Sum = %d\nMean = %d\nTemp = %d\nSigma = %f\n",sum,mean,temp,sigma);
}


