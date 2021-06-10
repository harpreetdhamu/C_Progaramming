#include<stdio.h>
void gswap(void*,void*,int);
int i; 
int main()
{
	char ch1 = 'A',ch2 = 'B';
	int n1 = 2049, n2 = 16342;
	float a1[3] = {1.5,6.36,17.5}, a2[3] = { 6.926,12.321,1.71};

	gswap(&ch1,&ch2,sizeof(ch1));
	printf("%c %c\n",ch1,ch2);

	gswap(&n1,&n2,sizeof(n1));
	printf("%d %d\n",n1,n2);
	
	gswap(a1,a2,sizeof(a1));
	for(i=0;i<3;i++)
	printf("%f",a1[i]);
	printf("\n");
	for(i=0;i<3;i++)
	printf("%f",a2[i]);
	printf("\n");
}

void gswap(void *p1,void *p2,int size)
{
	char temp;
	for(i=0;i< size;i++)
	{
		temp = *(char*)p1;
		*(char*)p1 =*(char*)p2;
		*(char*)p2 = temp;
	p1++;
	p2++;
	}
}
