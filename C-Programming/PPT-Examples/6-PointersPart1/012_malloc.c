#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char *ptr;
ptr = malloc(5); 
if (ptr != NULL)
{
strcpy(ptr,"chanchal");
	printf("%s\n",ptr);


/*
*ptr = 'A';
*(ptr+1) = 'P';
*(ptr+2) = 'P';
*(ptr+3) = 'l';
*(ptr+4) = 'l';
*(ptr+5) = 'e';

	printf("%s\n",ptr);*/
	return 1;
}
else
{
	printf("please provide a accurate value\n");
}
printf("%u\n",ptr);
return 0; 
}
