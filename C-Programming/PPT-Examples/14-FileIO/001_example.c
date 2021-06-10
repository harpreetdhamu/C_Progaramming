#include <stdio.h>

int main()
{
	FILE *fp;

	fp = fopen("test.txt", "w");
	/*error handling*/
	if (fp == NULL)
	{
		return 1;
	}
	fclose(fp);

	return 0;
}
