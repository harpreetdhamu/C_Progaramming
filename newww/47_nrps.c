#include<stdio.h>
#include<stdlib.h>
int main()
{
	char s[3] = {'a','b','c'};
	char temp;
	
	int size = 3;
	int len = 12;

	for(int i=0;i<len/size;i++)
	{
		temp = s[0];
		for(int j = 0;j<size - 2;j++)
		{
			s[j] = s[j + 1];
		}
		s[size - 1] = temp;
		for(int j = 0;j<size;j++)
		{
			printf("%c",s[j]);
		}
	}
}
