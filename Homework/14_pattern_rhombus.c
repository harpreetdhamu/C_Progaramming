/* ●
Print rhombus using for loops
 */

#include<stdio.h>

//int i,j;
int main()
{
	int i,j,Num,Middle,temp=0;
printf("Enter a Number :\n ");
scanf("%d",&Num);
	for(i=1;i<=Num;i++)
	{
		Middle=(Num + 1) / 2;
		i<=Middle?temp++:temp--;
		for(j=1;j<=Num;j++)
		{
			if(j>=Middle+1-temp && j<=Middle-1+temp)

				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	//return 0;
}
