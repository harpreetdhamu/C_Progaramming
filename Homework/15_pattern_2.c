/*Based on previous example print following pyramid

 */

#include<stdio.h>
#include<stdlib.h>
//int i,j;
int main()
{
	int i,j,n,k;
	printf("Enter a Number:\n ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	if (n > 5)
	{
		printf("\n\nError: Pattern isn't Possible.Please Enter Number Between 1-5 \n");
		break;
	
	}
			k=1;
		for(j=1;j<=n*2-1;j++)
		{
			if(j>=n+1-i && j<=n-1+i)
				//printf("*");
		printf("%d",k++);
			else
				printf(" ");
		}
		printf("\n");
	}
	//return 0;
}
