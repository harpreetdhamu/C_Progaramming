/*Based on previous example print following pyramid
  
*/

#include<stdio.h>

//int i,j;
int main()
{
int i,j,n,k;
printf("Enter a Number:\n ");
scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		k=1;
		for(j=1;j<=n;j++)
		{
			if(j>5-i)

				printf("%d",k++%10);
			else
				printf(" ");
		}
		printf("\n");
	}
	//return 0;
}
