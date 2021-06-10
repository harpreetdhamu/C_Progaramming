/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Read n & n floats in a float array ’store’. Print the values in sorted order without modifying or copying ’store’ 
Date:28-May-2019
 */


#include<stdio.h>
#include<stdlib.h>
char ch;
int size,i,j;
float sort(float*,int);/*Function Declaration*/
void generic_swap(void* p1, void *p2, int size);
int main()
{
	do 
	{

		float array[size];
		float min,max;
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
		printf("Do you want to continue (Y/N):\n");
		scanf("%s",&ch);
		getchar();
		if(ch == 'Y' || ch == 'y')
			continue;
		else if(ch == 'N' || ch == 'n')
			exit(1);
		else
		{
			printf("Wrong Input\n");
			exit(1);
		}

	}while(1);
	return 0;

}
/*Function of sorting the array without using third variable */
float sort(float *array,int size)
{

	for(i=0;i<size;i++)
	{
		for(j=i;j<size;j++)
		{
			if(array[i] > array[j])
				/*call the generic swap function to short the array*/
				generic_swap((array + i), (array + j), sizeof(int));
		}
	}

	return 0;
}
/*function to short the array using pointer*/
void generic_swap(void* p1, void *p2, int size)
{
	char temp;
	for (int i = 0; i < size; i++)
	{
		temp = *(char *)p1;
		*(char *)p1 = *(char *)p2;
		*(char *)p2 = temp;
		p1++;
		p2++;
	}
}

