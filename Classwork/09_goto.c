#include<stdio.h>
int main()
{
printf("hi\n");
goto L1;
printf("i will not appeared\n");
L1:
printf("you Jumped\n");
}
