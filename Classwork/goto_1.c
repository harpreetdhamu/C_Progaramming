#include<stdio.h>
int main()
{
int i;
i=0;
L1:
if (i<10)
	printf("%d\n",i);
i++;
goto L1;
printf("you Jumped\n");
}
