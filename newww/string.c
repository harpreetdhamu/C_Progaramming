/*   #include <stdio.h>
	 void main()
	 {
	 char *a[10] = {"hi", "hello", "how"};
	 int i = 0;
	 a[0] = "hey";
	 for (i = 0;i < 10; i++)
	 printf("%s,", a[i]);
	 }*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i,n;
	char *x = "Alice";
	n = strlen(x);
	printf("n = %d,",n);
//:Wq
	*x = x[n];
	for(i = 0; i <= n; i++)
	{
		printf("%s,",x);
		x++;
	}
	printf("\n",x);
	return 0;
}

