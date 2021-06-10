#include <stdio.h>
#include <ctype.h>
#include <string.h>
int palindrome(char s[])
{
	int l = 0, i;
	l=strlen(s);
	printf("length %d\n",l);
	for(i=0;i<l/2;i++)
	{
		if ( s[i] != s[l - 1 - i])
			return 0;
		else
			return 1;
	}
}

int main()
{
	int result = 0;
	char str1[100];
	puts("Enter a string 1 :");
	fgets(str1,100,stdin);
	//	result = palindrome(str1);
	(palindrome(str1))?puts("String is Palindrome"):puts("String is not Palindrome");
	return 0;
}

