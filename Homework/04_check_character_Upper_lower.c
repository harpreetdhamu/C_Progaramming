/*WAP to check whether character is
 * – Upper case
 * – Lower case
 * – Digit
 * – No of the above*/

#include<stdio.h>
//int Digit;
char ch;
int main()
{
 printf("Enter a Character:");
 scanf("%c", &ch);

 if (ch > 'A')
	 if (ch < 'Z')
 	{
 	printf("Character %c is UpperCase\n",ch);
 	}
	 else
	{
 	printf("Character %c is LowerCase\n",ch);
	}

 else if (ch > 48)
	if (ch < 57)
 	{
	printf("Number %c is Digit \n",ch);
 	}
        else
	{
	printf("Number %c is Digit \n",ch);
	}

 else
	{
 	printf("None of the above\n");
 	}
}
