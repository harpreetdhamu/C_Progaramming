
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char name[10];
	char id[10];

	scanf("%[^\n]", name);// ^ exclude everything
	printf("Name = %s\n", name);
	scanf("%[a-z A-Z]", name);
	printf("Name = %s\n", name);

	/* Need to address an Issue here!!! */
/*
	scanf("%[0-9]", id);
	printf("ID = %s\n", id);
*/
	return 0;
}
