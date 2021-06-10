#include <stdio.h>
#include <stdlib.h>
int main()
{
char *ptr = malloc(5);
ptr = ptr * 1; /* No */
ptr = ptr / 1; /* No */
return 0;
}
