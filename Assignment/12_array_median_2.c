/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap to find the median of two unsorted arrays 
Date:10-may-2019
 */


#include <stdio.h>
#include <stdlib.h>

int size, i ,j ,temp ,count = 0;
float median, sum = 0, totalmedian;
unsigned n = 1;
int main()
{
	int	array[size];
	printf("Enter the count between 1-2 \n");
	scanf("%d",&count);
	if(count > 2)
	{
		printf("Oops!!!! please enter a number between 1-2 \n");
		exit(1);
	}
	while(count >= 1)
	{

		/* enter the total size of first array and element of first array */
		printf("Size of array %d between 1-10\n", n);
		scanf("%d",&size);
		if(size > 10)
		{
			printf("Oops!!!! max array elements exceeded,please enter a number between 1-10 \n");
			exit(1);
		}
		printf("Enter a element of array%d:\n", n);
		for(i=0;i<size;i++)
		{
			scanf("%d",&array[i]);
		}

		/*check the if array index 1 is greater than array index 2  then swap the position and sorted the array in ascending order */
		for(i=0;i<size-1;i++)
		{
			for(j=0;j<size-1;j++)
			{
				if(array[j] > array[j+1])
				{
					temp=array[j];
					array[j]=array[j+1];
					array[j+1]=temp;
				}
			}
		}

		printf("Sorted array%d is\n", n);
		for(i=0;i<size;i++)
		{
			printf("%d,",array[i]);
		}
		printf("\n");
		/*find the median of array and print median*/
		printf("Median of array%d is\n", n);
		median= (array[(i - 1) / 2] + array[i / 2]) / 2.0;
		sum += median;
		printf("Median = %.2f\n\n",median);
		count--;
		n++;
	}


	/*find the total median of both array's and print total median*/
	printf("Total median of both array's is\n");
	totalmedian = sum / 2.0;
	printf("Totalmedian = %.2f\n\n",totalmedian);

}

