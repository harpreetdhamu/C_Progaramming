#include <stdio.h>

int main()
{
	char option;
	int age;
	float height;

	scanf("%c", &option);
	printf("The character is %c\n", option);
	scanf("%d", &age);
	printf("The integer is %d\n", age);
	scanf("%f", &height);
	printf("The float is %f\n", height);

	return 0;
}

