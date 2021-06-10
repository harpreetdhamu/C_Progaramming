#include <stdio.h>
int main()
{
int a[2][3] = {{1,2,3},{4,5,6}};
int **p;
p = a;
 printf("%p\n",*p);
}
