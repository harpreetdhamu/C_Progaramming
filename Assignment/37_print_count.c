/*
   Author Name: Chanchal Parkash
   organization name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:To write a program to count number of characters, words and lines, entered through
stdin buffer
Date:15-June-2019
 */

#include<stdio.h>
#include<stdlib.h>
char ch;
int main()
{
	do
	{
		int word_count = 0,ch_count = 0,line_count = 0, str;
		printf("Enter a string and to print a string with Ctrl + D\n");
		while((str = getc(stdin)) != EOF)
		{
			++ch_count;
			if(str == ' ')
				++word_count;
			if(str == '\n')
			{
				++line_count;
				++word_count;
			}
		}

		printf("\nnuber of character = %d\nno of word = %d\nno of lines = %d\n",ch_count,word_count,line_count);
		printf("Do you want to continue (y/n):\n");
		scanf("%s",&ch);
		if (ch == 'Y' || ch == 'y')
			continue;
		else if (ch == 'N' || ch == 'n')
			exit(1);
		else
		{
			printf("Wrong input\n");
			exit(2);
		}
	}while(1);

}

