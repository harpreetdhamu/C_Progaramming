/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap to print all ascii characters. 
Date:07-May-2019
 */


#include <stdio.h>

int i, value;
char ch;
int main()
{
	printf("Decimal\t Octal\t Hex\t Ascii\t\n");
	for(i=0;i<=127;i++)
	{
		value = i;
		ch = i;
		/*number 0 to 32 and 127 are non-printable character */
		if(ch<=32 || ch == 127)

			printf(" %d\t %o\t %x\t Non-printable\t\n",value,value,value);

		else
			printf(" %d\t %o\t %x\t %c\t\n",value,value,value,ch);
	}

	printf("\n");
}
