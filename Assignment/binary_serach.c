/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Read n & n floats in a float array ’store’. Print the values in sorted order without modifying or copying ’store’ 
Date:28-May-2019
 */


#include<stdio.h>
#include<string.h>

int sort_array(int *array,int size);
int scan_array(int *array,int size);
int print_array(int *array,int size);
int binary_search(int *array,int item);

int size,i,j,temp,item,low,mid,up,option;
char ch;
int main()
{

	int array[size];
	/* Enter the Total size of array */
	printf("Size of Array\n");
	scanf("%d",&size);

	/* Enter the Element of array */
	printf("Enter a Element of array:\n");
	scan_array(array,size);/*call the function to scanf the element of array*/
	sort_array(array,size);

	printf("Sorted Array is\n");
	print_array(array,size);/*call the function to print  sorted array */
	
	printf("Enter the item you want to search:\n");
	scanf("%d",&item);

	binary_search(array,item);/*call the function binary search*/

}
/*function to scan the element of array*/
int scan_array(int *array,int size)
{
	for(i=0;i<size;i++)
	{
		printf("array[%i] = ",i);
		scanf("%d",&array[i]);
	}
	printf("\n");
}
/*function to print the element of array*/
int print_array(int *array,int size)
{
	for(i=0;i<size;i++)
	{
		printf("%d,",array[i]);
	}
	printf("\n");
}
/*check the if array index 1 is greater than array index 2  then swap the position and sorted the array in ascending order */
int sort_array(int *array,int size)
{
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
}
/*function to search the whole array*/
int binary_search(int *array,int item)
{
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
