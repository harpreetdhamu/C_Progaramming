#include <stdio.h>

int main()
{
unsigned int count,iter;
printf("Enter a Hex Number:\n");
scanf("%X",&iter);

	for (count = 0; iter != 0; iter >>= 1)
	{
		if (iter & 01)
		{
			count++;
		}
	}

	printf("count is %d\n", count);

	return 0;
}
