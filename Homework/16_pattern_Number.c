/*Based on previous example print following pyramid

 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,Num,k=0,Col,Count;
	printf("Enter a Number:\n ");
	scanf("%d",&Num);
	for(i=1;i<=Num;i++)
	{
		if (Num < 3 || Num > 10)
		  {
		  printf("\n\nError: Pattern isn't Possible.Please Enter Number Between 1-10 \n");
		  break;

		  }
		Col=(Num+1)/2;
		i<=Col?k++:k--;
		Count=1;
		for(j=1;j<=Num;j++)
		{
			if(j>=Col+1-k && j<= Col-1+k)
			{
//				printf("*");
				printf("%d",Count);
				Count++;
			}
			else
			{
				printf(" ");
			//	Count--;
			}
		}
		printf("\n");
	}
	//return 0;
}
