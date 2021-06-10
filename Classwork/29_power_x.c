#include <stdio.h>
#include<stdlib.h>

int Power(int Base,int Num)
{
	int result;
	if (Num == 0) 
	{
		return 1;
	}
	else 
	{
result = (Base * Power (Base,Num -1));
		return result;
	}
	//		return 2* Power(number - 1);
}

int main()
{
	int ret,Num,Base;
	printf("Enter a Base 'B'\n");
	scanf("%d",&Base);
	printf("Enter a Number 'N'\n");
	scanf("%d",&Num);
	ret = Power(Base,Num);
	printf("power of %d^%d is = %d\n",Base,Num,ret);

	return 0;
}
