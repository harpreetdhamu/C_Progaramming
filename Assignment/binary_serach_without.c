/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Read n & n floats in a float array ’store’. Print the values in sorted order without modifying or copying ’store’ 
Date:28-May-2019
 */


#include<stdio.h>

int main()
{

	int size,i,j,temp,item,low,mid,up;
	int array[size];
	/* Enter the Total size of array */
	printf("Size of Array\n");
	scanf("%d",&size);

	/* Enter the Element of array */
	printf("Enter a Element of array:\n");
	for(i=0;i<size;i++)
	{
		printf("array[%i] = ",i);
		scanf("%d",&array[i]);
	}

	printf("\n");

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

	printf("Sorted Array is\n");
	for(i=0;i<size;i++)
	{
		printf("%d,",array[i]);
	}
	printf("\n");
	printf("Enter the item you want to search:\n");
	scanf("%d",&item);
	low = 1;
	up = size -1;

	do
	{
		mid = (low + up)/2;
		if(item > array[mid])
			low = mid + 1;
		if(item < array[mid])
			up = mid - 1;

	}while(low <= up && item != array[mid]);

	if(item == array[mid])
		printf("%d found at position %d\n",item,mid+1);
	else		
		printf("%d not found in array\n",item);

}
