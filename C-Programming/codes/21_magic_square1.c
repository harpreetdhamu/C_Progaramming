/* 
 * 
 * Author       :Abhijit
 * Orginazation :Emertxe
 * Title        : WAP to generate a n*n magic square (n is odd +ve no.)
 * Date         :10/06/2019
 *
 */
#include<stdio.h>
#define MAX 15
int main()
{
	int a[MAX][MAX], row, col, n, num;
	printf("Enter the odd value: ");
	scanf("%d", &n);
	/* assign value of row and coloumn */
	row=n-1;
	col=(n-1)/2;
/* in for loop check our 3 condition */ 
	for(num=1; num<=n*n; num++)
	{
		a[row][col]=num;
		row++;
		col--;
		if (num%n == 0)
		{
			row-=2;
			col++;
		}
		/* if row over flow the n value then its chk this condition */ 
		else if (row == n)
			row = 0;i
		/* if col is below the zero then its check this condition  */		
		else if (col == -1)
			col=n-1;
	}
	/* print the row and col  */
	for (row = 0; row < n; row++)
	{
	  	for(col = 0; col < n; col++)
		{
			printf("%4d\t",a[row][col]);
//			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
