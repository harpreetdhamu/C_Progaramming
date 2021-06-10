/*Based on previous example print following pyramid

 */

#include<stdio.h>
#include<stdlib.h>
//int i,j;
int main()
{
	int i,j,Num,k=0,Col;
	printf("Enter a Number:\n ");
	scanf("%d",&Num);
	for(i=1;i<=Num;i++)
	{
		/*if (Num > 9)
			{
			printf("\n\nError: Pattern isn't Possible.Please Enter Number Between 1-9 \n");
			break;

			}*/
Col=(Num+1)/2;
			i<=Col?k++:k--;
	//	Col=Num*2;
		for(j=1;j<=Num;j++)
		{
			if(j>=Col+1-k && j<= Col-1+k)
			{
				printf("*");
				//printf("%d",k);
				//j<4?k++:k--;
				//j<4?k++:(j>4?k--: );
	/*			if(j<Col/2)
				{
					k++;
				}
				else if (j>Col/2)
				{
					k--;
				}*/
			}
			else
			{
				printf(" ");
			//	if(j==Col/2)
			//		k--;
			}
		}
		printf("\n");
	}
	//return 0;
}
