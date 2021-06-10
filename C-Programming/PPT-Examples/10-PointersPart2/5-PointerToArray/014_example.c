#include <stdio.h>

int main()
{
	int (*p)[3],i,j;
	int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

	p = a;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			//printf("%d\n",a[i][j]);
			printf("%d\n",(*(p+i))[j]);
		}
	}

	return 0;
}
