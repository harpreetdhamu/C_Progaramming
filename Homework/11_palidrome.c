/*W.A.P to check whether a number is palindrome or not
 */

#include<stdio.h>

int Num,Reminder,Reverse=0,Original;
int main()
{
	printf("Enter a Two Numbers:\n ");
	scanf("%d",&Num);
Original=Num;
	while(Num != 0)
	{
		Reminder = Num % 10;
		Reverse = Reverse * 10 + Reminder;
		Num = Num / 10;
	}
	if(Original == Reverse)
	{
		printf("Number %d is Palindrome,",Original);
	}
	else
	{
		printf("Number %d is Not Palindrome,",Original);
	}
	return 0;
}
