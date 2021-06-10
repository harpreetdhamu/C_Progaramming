#include <stdio.h>
#include <stdlib.h>
int main()
{
char *ptr;
int iter;
ptr = malloc(5);
for (iter = 0 ; iter < 5; iter++)
{
ptr[iter] = 'A' + iter;
printf("%p\n",ptr[iter]);
printf("%c\n",ptr[iter]);
}
free(ptr);
ptr = NULL;
printf("%p\n",ptr);
return 0;
}

