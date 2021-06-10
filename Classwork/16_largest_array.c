

#include<stdio.h>
int main()
{
	int size,index,sum=0,Largest=0;
	printf("enter Size of array\n");
	scanf("%d",&size);
	int array[size];
	printf("Number of element\n");
	for(index=0;index<size;index++)
	{
		scanf("%d",&array[index]);
	}
Largest= array[0];
	for(index=0;index<size;index++)
	{	
if (array[index] > Largest)	
 
Largest = array[index];
}
///	Result=sum/size;
	printf("Largest Number Is %d\n",Largest);
}
