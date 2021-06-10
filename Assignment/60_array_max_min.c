/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP to find the median of two unsorted arrays 
Date:10-May-2019
 */


#include<stdio.h>

int size,i,j;
float sort(float*,int*);
int main()
{

	float array[size];
	float min,max;
	/* Enter the Total size of first array and element of first array */
	printf("Size of First Array\n");
	scanf("%d",&size);

	printf("Enter a Element of First array:\n");
	for(i=0;i<size;i++)
	{
		scanf("%f",&array[i]);
	}

	//	sort(array,&size);
	min = array[0];
	max = array[0];

	for(i=0;i<size;i++)
	{
		if(array[i] > min)
		{
			max = array[i];
		}
		if(array[i] < min)
		{
			min = array[i];
		}
	}
	printf("\n");
	printf("max element = %f\n",max);
	printf("min element = %f\n",min);
	/*printf("Sorted Array is\n");
	  for(i=0;i<size;i++)
	  {
	  printf("%f,",array[i]);
	  }
	  printf("\n");*/
}
/*float sort(float *array,int *size)
{

}*/
