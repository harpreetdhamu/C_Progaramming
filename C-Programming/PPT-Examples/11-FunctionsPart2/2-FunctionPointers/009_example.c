#include <stdio.h>
#include <stdlib.h>

static int *ptr;


void my_exit(void)
{
	printf("Exiting program\n");

	if (ptr)
	{
		/* Deallocation in my_exit */
		free(ptr);
	}
}

void test(void)
{
	puts("In test");

	exit(0);
}
int main()
{
	/*	
	 * Registering a callback 
	 * Function
	 */
	atexit(my_exit);
//my_exit();
//	*ptr = 100;
	/* Allocation in main */
	ptr = malloc(100);

	test();

	printf("Hello\n");

	return 0;
}
