/*
   Author Name: Chanchal Parkash
   organization name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:To find the average of n numbers by taking input in 3 different ways.
Date:10-june-2019
 */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(int argc,char *argv[],char *envp[])
{
	int option,num,temp,array[50],sum = 0,i,result = 0,inc = 0,count = 0;
	char ch,*ptr,*token;
	const char str[2] = " ";
	do
	{	

		printf("Select a function :\n1. Ist method(simple average calulate)\n2. 2nd method(command line average calulate)\n3. 3rd method(through environment variable average calulate)\nSelect a option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				{
					printf("Enter a number:\n");
					scanf("%d",&num);
					for(i = 0; i < num; i++)
					{
						printf("array[%i] = ",i);
						scanf("%d",&array[i]);
						sum += array[i];
					}
					printf("Sum = %d\nAverage of sum =  %.3f\n",sum,sum/(float)num);
				}


				break;
			case 2:
				{
					if (argc < 2)
					{
						printf("Invalid enter Atleast two number \n");
						exit(1);
					}
					for(i=1;i < argc; i++)
					{
						result = result+atoi(argv[i]);
					}
					printf("Sum = %d\nAverage of sum = %.2f\n",result,(float)result/(argc -1));
				}
				break;
			case 3:
				printf("Export a environment variable which contain numbers from shell\n");
			/* The getenv() function searches the environment list to find the environment variable name, and returns a pointer to the corresponding value string */	
				ptr = getenv("array");
				printf ("Array= %s.\n", ptr);
				/*The  strtok()  function  breaks  a string into a sequence of zero or more nonempty tokens.*/
				token = strtok(ptr, str);
				/*Splits ptr array according to given delimiters and returns next token. It needs to be called in a loop to get all tokens. It returns NULL when there are no more tokens.*/
				while( token != NULL )
				{
					inc++;
					/*convert string to integer*/
					array[inc] = atoi(token);
					sum += array[inc];
					token = strtok(NULL, str);
				}

				printf("Sum = %d\nAverage of sum = %.2f\n",sum,sum/(float)inc);
				break;
			default:
				printf("Wrong option\n");
				break;
		}
		sum = 0;

		printf("Do you want to continue(y/n)\n");
		scanf("%s",&ch);
		if (ch == 'Y' || ch == 'y')
		{
			continue;
		}
		else if (ch == 'N' || ch == 'n')
		{
			exit(1);
		}
		else
		{
			printf("Wrong input\n");
			exit(1);
		}
	}while(1);
}

