/* ●
Print rhombus using for loops and print number
 */

#include<stdio.h>

//int i,j;
int main()
{
	int i,j,Num,Middle,temp=0,k,New;
printf("Enter a Number :\n ");
scanf("%d",&Num);
	for(i=1;i<=Num;i++)
	{
		Middle=(Num + 1) / 2;
		i<=Middle?temp++:temp--;
		k=temp-1;
		for(j=1;j<=Num;j++)
		{
			if(j>=Middle+1-temp && j<=Middle-1+temp)
			{
			New=j<Middle?k++%10:k--%10;
				printf("%d",New);
			}
			else
				printf(" ");
		}
		printf("\n");
	}
	//return 0;
}
