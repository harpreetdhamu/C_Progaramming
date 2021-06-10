/*WAP to check whether character is
 * – Digit 0-9
 * – Lower case
 * – Uppercase
 * - Exit
 * – No of the above
 using Switch case
 */

#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
//#include<conio.h>
//int Digit;
char ch;
int main()
{
	while(1)
	{
 printf("\n1.Enter Digit 0-9");
 printf("\n2.Enter LowerCase");
 printf("\n3.Enter UpperCase");
 printf("\n4.Enter @ for Exit");
 printf("\n\n Enter a Character:");
 scanf("%c", &ch);

switch(ch)
{
	case 48 ... 57:
 				  	printf("Character %c is Digit\n",ch);
					break;
	case 'a' ... 'z':
 				  	printf("Character %c is Lowercase\n",ch);
					break;
	case 'A' ... 'Z':
 				  	printf("Character %c is Digit\n",ch);
					break;
	case '@':
					exit(1);				
	default:
 				  	printf("None of The Above");
					break;
 }
}
//getch();
return 0;

}

