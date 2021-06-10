#include <stdio.h>

int main()
{
	int num = 100,num2,num3, ret;

	printf("The enter a number [is 100 now]: ");
	//ret = scanf("%d", &num);
	ret = scanf("%d %c %f", &num,&num2,&num3);

	if (ret != 1)
	{
		printf("Invalid input. The number is still %d\n", ret);
		return 1;
	}
	else
	{
		printf("Number is modified with %d\n", ret);
	}

	return 0;
}
