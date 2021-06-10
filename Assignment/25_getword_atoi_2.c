/*
   Author Name: Chanchal Parkash
   organization name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Implement getword, atoi, itoa functions
Date:07-May-2019
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int temp, num, option, len;
/*function prototype */
int my_getword(char *word);
int my_atoi(char *str);
void my_itoa(int n, char *s);
char ch,str[50];
int main() 
{
	do
	{
		printf("Choose a Function:\n1.getworld\n2.atoi(ascii to integer)\n3.itoa(interger to ascii)\n");
		printf("Enter a option:\n");
		scanf("%d",&option);
		getchar();
		switch(option)
		{
			case 1:
				printf("Enter a String:\n");
				fgets(str,50,stdin);
				printf("You enter String :\n");
				/*store the string length in len variable*/
				len = strlen(str);
				/*pass the address of string to getword function */
				temp = my_getword(str);
				printf("%s %d\n",str,temp);
				break;
			case 2:
				printf("Enter a numeric String:\n");
				fgets(str,50,stdin);
				printf("String to integer is:\n");
				/*pass the address of string to atoi function */
				temp = my_atoi(str);
				printf("%d\n",temp);
				break;
			case 3:
				printf("Enter a numeric String:\n");
				scanf("%d",&num);
				printf("Integer to string is:\n");
				/*store the string length in len variable*/
				len = strlen(str);
				/*pass the address of string to itoa function */
				my_itoa(num,str);
				printf("%s\n",str);
				break;
			default:
				printf("Wrong option\n");
				break;

		}


		printf("Do you want to continue (Y/N):\n");
		scanf("%s",&ch);
		getchar();
		if(ch == 'Y' || ch == 'y')
			continue;
		else if(ch == 'N' || ch == 'n')
			exit(1);
		else
		{
			printf("Wrong Input\n");
			exit(1);
		}

	}while(1);
	return 0;
}
/*Function should read a string from user and store them in the char address.Function should return the length of word. */
int my_getword(char *word)
{
	int count = 0;
	while(*word != '\0')
	{
		if(*word != '\n')
			count++;
		*word++;
	}
	return count  ;
}
/*Function for string to integer*/
int my_atoi(char *str)
{
	//int len = strlen(str);
	int i, num = 0, ret = 0;;
	while (*str >= 48 && *str <= 57) 
	{
		/*calculation for given number character by character.*/
		ret = 10 * ret + *str++ - '0';
	}
	return ret;
	/* 
	   for (i = 0; i < len; i++)
	   {
	   num = num + ((str[len - (i + 1)] - '0') * pow(10, i));
	   }
	   return num;*/
}


/* The function will recieve a string and covert the number stored in the string into exact integer number. Return the number.*/
void my_itoa(int num,char *str)
{
	int i, rem, len = 0, n;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}

