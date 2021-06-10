/*	Author Name : Shritij Shere
 *	Organisation Name : EMERTXE
 *	Title : Program to implement myscanf
 *	Date : 22/6/2019
 */

#include <stdio.h>
#include <stdarg.h>

/* Function Prototype */
void my_scanf(const char *format, ...);

int main()
{
	/* Declare the variables */

	int a;
	char c; 
	char *s;
	float d;

	/* Read the variables and call the function */

	printf("Enter the number ");
	my_scanf ("%d",&a);

	printf("Enter the character ");
	my_scanf ("%c",&c);

	printf("Enter the float value ");
	my_scanf ("%f",&d);

	printf("Enter the string ");
	my_scanf ("%s",s);
}

void my_scanf (const char *fmt, ...)
{
	/* Initialise object of type va_list */
	va_list ap;
	/* Initialising ap */
	va_start(ap, fmt);

	int *d , i = 0;
	const char *p = fmt;

	/* Scan  the format specifier */
	switch(*++p)
	{
		case 'd':
			{
				d = va_arg(ap, int *);
				while(*d != '\n')
				{
					/* Get the character and print the digits one by one */
					*d = getchar();
					if(*d >= 48 && *d <= 57)
					{
						if(!i++)
						{
							printf("you entered ");
						}
						putchar(*d);
					}
				}	
				printf("\n");
			}
			break;

		case 'c':
			{
				char *c = va_arg(ap, char *);
				do{
					/* Get the character and print the character */
					*c = getchar();
					if(!i++)
					{
						printf("you entered ");
					}
					putchar(*c);
				}while(*c != '\n');
			}
			break;

		case 'f':
			{
				float *d  = (float *)va_arg(ap, float*);
				do
				{
					*d = getchar();
					if(!i++)
					{
						printf("You entered ");
					}
					putchar(*d);

				}while(*d !='\n');
			}
			break;

		case 's':
			{
				/* Get the character and print the characters one by one */
				char *d  = va_arg(ap, char *);
				while(*d !='\n')
				{
					*d = getchar();
					if(!i++)
					{
						printf("You entered ");
					}

					putchar(*d);
				}
			}
			break;
	}
}
