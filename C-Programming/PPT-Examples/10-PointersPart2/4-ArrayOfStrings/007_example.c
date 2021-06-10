#include <stdio.h>

int main()
{
	int i, j;
	char s[3][8] = {
		"Array",
		"of",
		"Strings"
	};
	for(i= 0;i<=3;i++)
	{

		for(j= 0;s[i][j] !='\0';j++)
		{

			printf("%c\n",  s[i][j]);
		}
	}
//	printf("%s %s %s\n", s[0], s[1], s[2]);
//	printf("%c %c %c\n", s[0][0], s[1][1], s[2][4]);
	return 0;
}
