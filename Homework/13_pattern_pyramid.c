/*Based on previous example print following pyramid
  
 *
 * * *
 * * * * *
 * * * * * * *
 */

#include<stdio.h>

//int i,j;
int main()
{
int i,j,n;
printf("Enter a Number:\n ");
scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n*2-1;j++)
		{
			if(j>=n+1-i && j<=n-1+i)

				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	//return 0;
}
