/*
   Author Name: Chanchal Parkash
   organization name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP to generate a n*n magic square (n is odd +ve no.)
Date:10-june-2019
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int option;
char ch;
int array[50][50],num,j = 0,i = 0;
/* Function prototype*/
void clear_mem(void);
void magic_square(int n,int (*)[50]);

int main()
{
	do
	{	
		int n;
		printf("Enter a num:\n");
		scanf("%d",&n);
		if (n % 2 == 0)
		{
			printf("Magic square is not possible,please enter a +ve odd no only\n");
			exit(1);
		}

		magic_square(n,array);
		for(i=0;i < n;i++)
		{
			for(j=0;j < n;j++)
			{
				printf("%6d",array[i][j]);
			}
			printf("\n");
		}

		printf("The Magic Square for n=%d:\nSum of each row or column %d:\n\n",  n, n*(n*n+1)/2); 

		clear_mem();
		printf("Do you want to continue(y/n)\n");
		scanf("%s",&ch);
		/*if (ch == 'Y' || ch == 'y')
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
		  }*/
	}while(ch == 'y' || ch == 'Y');
}
/*function to clear the memory in array*/
void clear_mem(void)
{
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<50;j++)
			array[i][j] = '\0';
	}
}
/*function of magic square*/
void magic_square(int n,int (*array)[50])
{
	int num = 1,j = 0,i = 0;
	/*intialize the row and coloumn where number 1 is stored*/
	i = n / 2;
	j = n - 1;
	//for(num = 1; num <= n*n;)
	while(num <= n*n)
	{
		/*if both i and j are out of bounds the i = 0 and j = n -2*/
		if(i == -1 && j == n)
		{
			i = 0;
			j = n - 2;
		}
		else
		{
			/*if j is greater or equal the given number then j = 0 and i is less than 0 then i = n -1 */
			if(j == n)
				j = 0;
			if (i < 0)
				i = n - 1;
		}
		if(array[i][j])
		{
			/*if position is occupied */
			j -=2;
			i++;
			continue;
		}
		else
			/*stored the number one by one*/
			array[i][j] = num++;
		i--;j++;
	}
	return;
}



