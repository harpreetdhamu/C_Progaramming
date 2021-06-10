/*Based on previous example print following pyramid

 */

#include<stdio.h>
#include<stdlib.h>
//int i,j;
int main()
{
	int i,j,Num,k,Col;
	printf("Enter a Number:\n ");
	scanf("%d",&Num);
	for(i=1;i<=Num;i++)
	{
			if (Num > 9)
			{
			printf("\n\nError: Pattern isn't Possible.Please Enter Number Between 1-9 \n");
			break;

			}
		k=1;
		Col=Num*2;
		for(j=1;j<=Col;j++)
		{
			if(j<=Num+1-i || j>=Num+i)
			{
				printf("%d",k);
				//j<4?k++:k--;
				//j<4?k++:(j>4?k--: );
				if(j<Col/2)
				{
					k++;
				}
				else if (j>Col/2)
				{
					k--;
				}
			}
			else
			{
				printf(" ");
				if(j==Col/2)
					k--;
			}
		}
		printf("\n");
	}
	//return 0;
}
