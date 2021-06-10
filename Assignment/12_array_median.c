/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP to find the median of two unsorted arrays 
Date:10-May-2019
 */


#include<stdio.h>

int Size,Size1,i,j,temp,temp1;
float Median,Median1,TotalMedian;
int main()
{

	int	array[Size],array1[Size1];

	/* Enter the Total size of first array and element of first array */
	printf("Size of First Array\n");
	scanf("%d",&Size);

	printf("Enter a Element of First array:\n");
	for(i=0;i<Size;i++)
	{
		scanf("%d",&array[i]);
	}

	/*check the if array index 1 is greater than array index 2  then swap the position and sorted the array in ascending order */
	for(i=0;i<Size-1;i++)
	{
		for(j=0;j<Size-1;j++)
		{
			if(array[j] > array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}

	printf("Sorted Array is\n");
	for(i=0;i<Size;i++)
	{
		printf("%d,",array[i]);
	}
	printf("\n");
	/*Find the median of first array and print median*/
	printf("Median first Array is\n");
	Median= (array[(i-1)/2]+array[i/2])/2.0;

	printf("Median = %f\n\n",Median);

	/* Enter the Total size of Second array and element of Second array */
	printf("Size of Second Array\n");
	scanf("%d",&Size1);

	printf("Enter a Element of Second array:\n");
	for(i=0;i<Size1;i++)
	{
		scanf("%d",&array1[i]);
	}

	/*check the if array1 index 1 is greater than array1 index 2  then swap the position and sorted the array1 in ascending order */
	for(i=0;i<Size1-1;i++)
	{
		for(j=0;j<Size1-1;j++)
		{
			if(array1[j] > array1[j+1])
			{
				temp1=array1[j];
				array1[j]=array1[j+1];
				array1[j+1]=temp1;
			}
		}
	}

	printf("Sorted Array1 is\n");
	for(i=0;i<Size1;i++)
	{
		printf("%d,",array1[i]);
	}
	printf("\n");

	/*Find the median of Second array and print median*/
	printf("Median Second Array is\n");
	Median1= (array1[(i-1)/2]+array1[i/2])/2.0;
	printf("Median1 = %f\n\n",Median1);

	/*Find the Total Median of Both array's and print Total Median*/
	printf("Total Median of Both Array's is\n");
	TotalMedian=(Median+Median1)/2.0;
	printf("TotalMedian = %f\n\n",TotalMedian);

}

