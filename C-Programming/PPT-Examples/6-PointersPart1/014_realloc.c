#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char *ptr;
	ptr = malloc(5); 
	printf("%p\n",ptr);
	strcpy(ptr,"chanchal");
	printf("%s\n",ptr);
/*

	ptr = realloc (ptr,20);
	printf("%p\n",ptr);
	strcpy(ptr,"singlachanchal singla");
	printf("%s\n",ptr);

	ptr = realloc (ptr,22221);
	printf("%p\n",ptr);
	strcpy(ptr,"chanchal parkash singla 1234556");

	printf("%s\n",ptr);
	
	ptr = realloc (ptr,11122221);
	printf("%p\n",ptr);
	strcpy(ptr,"chanchal parkash singla 1234556");
	printf("%s\n",ptr);

*/
	return 0; 
}
