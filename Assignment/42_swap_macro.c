/*
   Author Name: Chanchal Parkash
   organization name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:To define a macro swap (t, x, y) that interchanges two arguments of type t.
Date:15-June-2019
 */


#include <stdio.h>
#include <stdlib.h>
/*macro of swaping the user input values*/
#define SWAP(num1,num2, type) \
{                  \
	type temp = num1;   \
	num1 = num2;      \
	num2 = temp;    \
}
char ch;
int main()
{
	do
	{
		int op;
		printf("Select a data type\n1. int\n2. char\n3. float\n4. double\nSelect a option\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
					printf("Enter a number\n");
					int n1,n2;
					scanf("%d %d",&n1,&n2);
					printf("after swapping\n");
					SWAP(n1,n2,int);/*replace the macro here when program is run*/
					printf("%d,%d,\n",n1,n2);
				}
				break;
			case 2:
				{
					printf("Enter a character\n");
					char n1,n2;
					scanf("%s %s",&n1,&n2);
					getchar();
					printf("after swapping\n");
					SWAP(n1,n2,char);/*replace the macro here when program is run*/
					printf("%c,%c,\n",n1,n2);
				}
				break;
			case 3:
				{
					printf("Enter a number\n");
					float n1,n2;
					scanf("%f %f",&n1,&n2);
					printf("after swapping\n");
					SWAP(n1,n2,float);/*replace the macro here when program is run*/
					printf("%g,%g,\n",n1,n2);
				}
				break;
			case 4:
				{
					printf("Enter a number\n");
					double n1,n2;
					scanf("%lf %lf",&n1,&n2);
					printf("after swapping\n");
					SWAP(n1,n2,double);/*replace the macro here when program is run*/
					printf("%.2lf,%.2lf,\n",n1,n2);
				}
				break;
			default:
				printf("Wrong Option\n");
				break;
		}
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
