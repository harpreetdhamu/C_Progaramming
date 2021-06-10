#include<stdio.h>
int main()
{
	int a[4] ={1,2,3,4};
	int c =3;
	int b[4] ={1,2,3,4};
	int n = &b[3] -& a[2];
	printf("%u %u %u\n",a,b,&c);
	printf("%u %u\n",&b[3],&a[2]);
	printf("%d" ,n);

}


