#include <stdio.h>

/* Factorial of 3 numbers */

int Sum_Sequence(int number)
{
	if (number <= 1) /* Base Case */
	{
		return 1;
	}
	else /* Recursive Case */
	{
		return number + Sum_Sequence(number - 1);
	}
}

int main()
{
	int ret,Num;
printf("Enter a Number 'N'\n");
scanf("%d",&Num);
	ret = Sum_Sequence(Num);
	printf("Sum of sequence is = %d\n", ret);

	return 0;
}
