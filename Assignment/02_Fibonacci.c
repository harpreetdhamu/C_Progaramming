/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap to generate fibbonacci numbers <= 'n' 
Date:02-May-2019
 */


#include <stdio.h>

int limit, num1=0, num2=1, i, sum;
int main()
{
	printf("Enter a number:\n");
	scanf("%d",&limit);
	/**/	
	//	sum=num2+num3;
	for(i=0;i<=limit;i++)
	{

		sum = num1 + num2;
		if(sum <= limit)
		{
			printf("%d,",sum);
		    sum = num1 + num2;
			num1 = num2;
			num2 = sum;
			//printf("%d,",sum);
			//	sum=num2+num3;
		}
	}
	printf("\n");
}
