

#include<stdio.h>
int main()
{
	int size,index,sum=0,Result;
	printf("enter Size of array\n");
	scanf("%d",&size);
	int array[size];
	printf("Number of element\n");
	for(index=0;index<size;index++)
	{
		scanf("%d",&array[index]);
	}

	for(index=0;index<size;index++)
	{
		sum=sum+array[index];
	} 

	Result=sum/size;
	printf("average %d\n",Result);
}
