/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Read a string and print it in reverse without storing in an array using recursive
method OR non-recursive method 
Date:10-may-2019
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int size, i , j,len, option;
char str1[50],*str2,ch;

/*function Prototype for recursion */
void reverse_recur(char *str); 
void reverse(char *str1);/*function Prototype */
int main()
{
	do
	{
		printf("Select a Reverse Function\n\n1.Recursion_Reverse_String\n2.Reverse_String\n\nEnter a Option:\n");
		scanf("%d",&option);
		getchar();
		switch(option)
		{
			case 1:
				printf("Enter the string \n");
				fgets(str1,50,stdin);
				fflush(stdin);
				/*pass the address of str1 to function recursive reverse*/
				reverse_recur(str1);
				printf("\n");
				break;
			case 2:
				printf("Enter the string \n");
				fgets(str1,50,stdin);
				fflush(stdin);
				reverse(str1);/*pass the address of str1 to function reverse*/
				printf("\n");
				break;
			default:
				printf("Wrong option\n");
				break;
		}

		printf("Do you want to continue(Y/N)\n");
		scanf("%s",&ch);
		getchar();
		if(ch == 'Y' || ch == 'y' )
			continue;
		else if(ch == 'N' || ch == 'n' )
			exit(1);
		else
		{
			printf("Wrong Input\n");
			exit(1);
		}
	}while(1);
}

/*Function of reverse string */
void reverse(char *str1)
{
	int iter;
//	len = strlen(str1);
	char temp;
	printf("Reverse String is:\n");
	for(iter = strlen(str1) - 1; iter !='\0'; iter--)
	{
		printf("%c",str1[iter]);
	}
}

/*Function of reverse string using recursion*/
void reverse_recur(char *str) 
{ 
	if (*str) 
	{ 
		/*Function calling itself: Recursion*/
		reverse_recur(str+1); 
		printf("%c", *str); 
	}
}
/*Recursive function (reverse) takes string pointer (str) as input and calls itself with next location to passed pointer (str+1). Recursion continues this way, when pointer reaches ‘\0’, all functions accumulated in stack print char at passed location (str) and return one by one.*/
