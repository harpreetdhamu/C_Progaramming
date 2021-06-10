#include <stdio.h>

void print_array(int array[]);

int main()
{
	int array[5] = {10, 20, 30, 40, 50};

	print_array(array);

	return 0;
}

void print_array(int array[])
{
	int	iter;
	float result;

	for (iter = 0; iter < 5; iter++)
	{
result = result + array[iter] /5.0;

		//printf("Index %d has Element %d\n", iter, array[iter]);
	}
	printf("Average of array %.2f\n",result);
}
