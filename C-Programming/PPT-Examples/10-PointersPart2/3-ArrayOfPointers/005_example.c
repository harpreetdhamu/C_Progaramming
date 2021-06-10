#include <stdio.h>

int main()
{
	int a[2] = {10, 20};
	int b[2] = {30, 40};
	int c[2] = {50, 60};
	int i,j;
	int *ptr[3];

	ptr[0] = a;
	ptr[1] = b;
	ptr[2] = c;
	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
//			printf("%d,",ptr[i][j]);

			printf("%d,",*(*(ptr+i)+j));
					}
					printf("\n");
					}
					return 0;
}

