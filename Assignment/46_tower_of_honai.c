/*
   Author Name: Chanchal Parkash
   organization name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP implement the solution for tower of hanoi.
stdin buffer
Date:15-June-2019
 */

#include<stdio.h>
#include<stdlib.h>
char ch, start = 'A',aux = 'B', dest = 'c';
int num;
/*Function prototype tower of honai*/
void tower_of_honai(int num,char start,char aux,char dest);
int main()
{
	do
	{
		printf("Enter a Num:\n");
		scanf("%d",&num);
		/*call the function and pass the values of num,start,auxulary,destination*/
		tower_of_honai(num,start,aux,dest);
		printf("\n");
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

/*recursive fumction of tower of honai*/
void tower_of_honai(int num,char start,char aux,char dest)
{
	if(num >= 1)
	{
		
			tower_of_honai(num-1,start,dest,aux);
			printf("Tower Number %d: move %c to %c\n",num,start,dest);
			tower_of_honai(num-1,aux,start,dest);
		
	}
}


