/*WAP Simple calculator using Switch case
 */

#include<stdio.h>
#include<conio.h>
//int Digit;
char op;
int Num1,Num2,result;
int main()
{
 printf("Enter a Num1 Operator Num2:\n");
 scanf("%d %c %d",&Num1,&op,&Num2);


switch(op)
{
	case '+' :
					result=Num1 + Num2;
 				  	printf("Sum of two Numbers is %d\n",result);
					break;
	case '-' :

					result=Num1 - Num2;
 				  	printf("Difference of two Numbers is %d\n",result);
					break;
	case '/' :
					result=Num1 / Num2;
 				  	printf("Division of two Numbers is %d\n",result);
					break;
	case '*' :
					result=Num1 * Num2;
 				  	printf("Multipilcation of two Numbers is %d\n",result);
					break;
	default:
 				  	printf("None of The Above");
 }
return 0;

}

