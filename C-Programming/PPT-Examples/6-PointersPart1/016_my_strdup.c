#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *my_strdup(const char *s);
int main()
{
	char *ptr;
	
printf("%s",my_strdup("sing"));
	free(ptr);
	return 0;
}
char *my_strdup(const char *s)
{

	//char *p = malloc(strlen(s) +1 );
	char *p = malloc(5);
	return strcpy (p,s);
}
