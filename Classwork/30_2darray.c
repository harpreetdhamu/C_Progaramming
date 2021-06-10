#include<stdio.h>
int a[3][2],i,j;
int max,min;
int main()
{

	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("a[%d][%d]==",i,j);
			scanf("%d",&a[i][j]);
		}
	}
/*	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d ",a[i][j]);
		}
	}*/
		max = a[0][0];
		min = a[0][0];


		for(i=0;i<3;i++)
		{
			for(j=0;j<2;j++)
			{
				if(a[i][j] > max)
				{
					max = a[i][j];
				}
				if(a[i][j] < max)
				{
					min = a[i][j];
				}
			}
		}
			printf("max element = %d\n",max);
			printf("min element = %d\n",min);
	}
