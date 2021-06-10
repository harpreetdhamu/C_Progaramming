/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Read n & n floats in a float array ’store’. Print the values in sorted order without modifying or copying ’store’ 
Date:28-May-2019
 */


#include<stdio.h>

int size,i,j;
float sort(float*,int);/*Function Declaration*/
int main()
{

	float array[size];
	/* Enter the Total size of array */
	printf("Size of Array\n");
	scanf("%d",&size);

	/* Enter the Element of array */
	printf("Enter a Element of array:\n");
	for(i=0;i<size;i++)
	{
		printf("array[%i] = ",i);
		scanf("%f",&array[i]);
	}

	printf("\n");
	/*call the sort fuction and pass the address of array and size*/
	sort(array,size);

	printf("Sorted Array is\n");
	for(i=0;i<size;i++)
	{
		printf("%.1f,",array[i]);
	}
	printf("\n");

}
/*Function of sorting the array without using third variable */
float sort(float *array,int size)
{
	float min, max,min2;
	min = max = min2 = array[0];

	for(i = 0; i < size; i++)
	{
		if(array[i] < min)
			min = array[i];
		if(array[i] > max)
			max = array[i];
	}
	printf("%g\n",min);
	while(min != max)
	{
		for(i = 0; i < size; i++)
		{
			if (array[i] != min && array[i] > min)
			{
				min2 = array[i];
				break;
			}
		}
		for(i = 0; i < size; i++)
		{
			if (array[i] < min && array[i] > min)
			{
				min2 = array[i];

			}
			printf("%g\n",min2);
			min = min2;
		}
	}
	return 0;
}
