#include <stdio.h>

int main()
{
	char ch = 'y';

	printf("Enter a string: ");

	while (ch != 'n')
	{
		scanf("%c", &ch);
	//	__fpurge(stdin);//clear the buffer
		while (getchar() !='\n');//fpurge function clear tthe buffer
		printf("%c\n", ch);
	}

	return 0;
} 
