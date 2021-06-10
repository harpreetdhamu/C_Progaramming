#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *input_fp;
	int ch;
	input_fp = fopen("text_copy.txt", "w");

	if (input_fp == NULL)
	{   
		return 1;
	}
	for ( ; (ch = getc(input_fp)) != EOF; )
	{
	putc(ch,input_fp);
	}
	fclose(input_fp);

	return 0;
}
