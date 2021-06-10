/*	Author Name : Shritij Shere
 *	Organisation Name : EMERTXE
 *	Title : Program to implement myprintf
 *	Date : 22/6/2019
 */


#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/* Function Protoype */
void my_printf(char *fmt, ...);

int main()
{
	/* Declaring the variables */
    char *s1 = "First";
    int  d = 42;
    char c = 'a';

	/* Calling the function */
    my_printf("%s", s1);
    my_printf("%d", d);
    my_printf("%c", c);

    return 0;
}
void my_printf(char *fmt, ...)
{
	/* Declaring object of type va_list */
	va_list ap;
	int d;
	char c, *s;

	/* Initialising ap */
	va_start(ap, fmt);

	while (*fmt)
	{
		/* Print type depending on the format specifier */
		switch (*fmt++) 
		{
			case 's':
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;

			case 'd':
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;

			case 'c':
				c = (char) va_arg(ap, int);
				printf("char %c\n", c);
				break;
		}
	}
	va_end(ap);
}
