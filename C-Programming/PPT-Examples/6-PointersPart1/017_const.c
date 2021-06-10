#include <stdio.h>
int main()
{
const int num = 100;
int *iptr = &num;
printf("Number is %d\n", *iptr);
//num = 200;
*iptr = 200;
printf("Number is %d\n", num);
return 0;
}
