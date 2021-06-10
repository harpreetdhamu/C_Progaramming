#include <stdio.h>
#include <stdlib.h>
int main()
{
int *ptr = (char*)1000;
int *ptr2 = (char*)1010;
printf("%d\n",ptr - ptr2);
printf("%d\n",ptr2 - ptr);
return 0;
}
