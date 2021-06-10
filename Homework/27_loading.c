#include <stdio.h>
#include <unistd.h>
#include <curses.h>
char end = ']', prog = '-';
int i , j,sum=0;
int main()
{
	for(i=0;i<=10;i++)
	{
		sum = i * 10;
		printf("%*c",25,end);
		printf("%d%%\r",sum);
		fflush(stdout);
		printf("[");
		for(j=0;j<=8;j++)
		{
			printf("%c",prog);
			fflush(stdout);
			sleep(1);
		}
	}
	printf("\n");
}
