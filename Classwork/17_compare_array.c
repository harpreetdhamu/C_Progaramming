

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int size,i,j,sum=0,count=0;
	
	printf("enter Size of array\n");
	scanf("%d",&size);
	
	int array1[size],array2[size];
	printf("Number of element\n");
	
	for(i=0;i<size;i++)
	{
		scanf("%d",&array1[i]);

	}

	for(i=0;i<(size-1);i++)
	{
		for(j=(i+1);j<=size;j++)
		{
			if (array1[i] == array1[j])	
			{
				printf("Enter Unique Number\n");
			exit(0);
			}
		}
	
	}

	printf("Number of element 2\n");
	for(j=0;j<size;j++)
	{
		scanf("%d",&array2[j]);
	}
	for(i=0;i<size;i++)
	{
		for(j=0;j<=size;j++)
		{
			if (array1[i] == array2[j])	
			{
	//			printf("Enter Unique Number\n");
				count++;
		//	exit(0);
			}
		}
	}
	if(count == size)
		printf("equal\n");
	else
		printf("not equal");
	return 0;
}
