#include <stdio.h>

int main()
{
	if (sizeof(float *) == sizeof(long long *))
	{
		printf("Yes its Equal\n");
	}

	return 0;
}
