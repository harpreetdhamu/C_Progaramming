/*W.A.P to check Year is Leap or Not
 */

#include<stdio.h>

int main()
{
	int Year;
	printf("Enter a Year:\n ");
	scanf("%d",&Year);

	if(Year % 100 == 0)
	{
		if(Year % 400 == 0)
		{
			printf("Year %d is Leap Year\n",Year);
		}
		else
		{
			printf("Year %d is Not Leap Year\n",Year);
		}
	}
	else
	{
		if(Year % 4 == 0)
		{

			printf("Year %d is Leap Year\n",Year);
		}
		else
		{

		printf("Year %d is Not Leap Year\n",Year);
		}

	}
		return 0;
	
}
