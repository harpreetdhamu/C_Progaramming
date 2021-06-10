/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP to implement my_scanf() function. 
Date:15-June-2019
 */


#include<stdio.h>
#include<stdlib.h>
#include <stdarg.h>
#include<string.h>
int option,num;
float f;
double d1;
char ch,character,str[30],str1[30];
void my_printf(char *fmt, ...);
void my_itoa(int num,char *str);
int main()
{
	do
	{

		printf("Select the function\n1. my_scanf\n2. my_printf\nSelect a Option\n");
		scanf("%d",&option);
		getchar();
		switch (option)
		{
			case 1:
				break;
			case 2:
				puts("Enter a num, character, string, float,double:\n");
				scanf("%d %c %s %f %lf",&num,&character,str,&f,&d1);
				my_printf("%d %c %s %f %lf\n", num,character,str,f,d1);
				break;
			default:
				printf("You enter a Wrong Option\n");
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


void my_printf(char *format, ...)
{
	va_list ap;/*This line declares a variable, ap, which we use to manipulating the argument list containing variable arguments of my_printf()*/
	int d;
	char c, *s;
	const char *str = format;
	float f;
	double d1;

	va_start(ap, format);/*This line initializes ap variable with function’s last fixed argument i.e. format. va_start() uses this to figure out where the variable arguments begin.*/
	while (*str)
	{
		if(*str++ == '%')
		{
			switch (*str) 
			{
				case 's':              /* string */
					s = va_arg(ap, char *);/*va_arg() fetches the next argument from the argument list. The second parameter to va_arg() is the data type of the argument we expect. */
					puts("\nyou entered a string are:");
					puts(s);
					break;
				case 'd':              /* int */
					d = va_arg(ap, int);
					gcvt(d,10,str1);
					/*if(d < 0)
					{
						d = -d;
						putchar('-');
					}
					my_itoa(d,str1);*/
					puts("\nyou entered a number are:");
					fputs(str1,stdout);
					break;
				case 'c':              /* char */
					/* need a cast here since va_arg only  takes fully promoted types */
					c = (char) va_arg(ap, int);
					puts("\nyou entered a character are:");
					putchar(c);
					break;
				case 'f':              /* float */
					/* need a cast here since va_arg only  takes fully promoted types */
					f =(float) va_arg(ap, double);
					/*gcvt - convert a floating-point number to a string*/
					gcvt(f,6,str1);
					puts("\nyou entered a float number are:");
					fputs(str1,stdout);
					puts("\n");
					break;
				case 'l':              /* double */
					if('f' == 'f')
					/* need a cast here since va_arg only  takes fully promoted types */
					d1 = va_arg(ap, double);
					/*gcvt - convert a floating-point number to a string*/
					gcvt(d1,6,str1);
					puts("\nyou entered a double number are:");
					fputs(str1,stdout);
					puts("\n");
					break;
				default:
					break;
			}
		}
		va_end(ap);
	}
}

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
