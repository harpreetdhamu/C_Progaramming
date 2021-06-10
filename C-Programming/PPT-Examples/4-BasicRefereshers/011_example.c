#include <stdio.h>

int main()
{
	int option;

	printf("Enter the value\n");
	scanf("%d", &option);

	switch (option)
	{
		case 10:
			printf("You entered 10\n");
			break;
		case 20:
			printf("You entered 20\n");
			break;
		default:
			printf("Try again\n");
	}

	return 0;
}
