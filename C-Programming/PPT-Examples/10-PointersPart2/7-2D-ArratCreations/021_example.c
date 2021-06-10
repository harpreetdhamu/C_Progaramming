#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **a;
	int i,j;

	a = malloc(2 * sizeof(int *));

	for (i = 0; i < 2; i++)
	{
		a[i] = malloc(3 * sizeof(int));
	}

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("array[%d] = ",j);
			scanf("%d",&a[i][j]);
		}
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d,",a[i][j]);
		}
	}




	return 0;
}
