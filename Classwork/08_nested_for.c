#include<stdio.h>
int main()
{
	int i,j;
	while(i<10)
	{
		//continue;
		for(j=0;j<10;j++)
		{
			//continue;
			printf("%d %d ",i,j);
			//			break;
		}
		i++;
		printf("\n");
		//continue;
		//break;
	}
}
