/*
   Author Name      : Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title			 :Given a number n, WAP to print all primes smaller than or equal to n. Use Sieve of Eratosthenes method 
Date			 :14_june_2019
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int num,power,i,j;
char ch;
int main()
{
	do
	{
		printf("Enter a number:\n");
		scanf("%d",&num);
		power = pow(2,20);
		/* if number is greater than 2^20 and number is negative then exit */
		if (num > power)
		{
			printf("Error!!! invalid input");
			exit(1);
		}
		else if ( num < 0)
		{
			printf("Error!!! invalid input");
			exit(2);

		}
		int prime[num + 1];
		/*store array with naturals numbers*/
		for(i = 2;i <= num;i++)
			prime[i] = i;


		for (i=2;i<num;i++)
		{
			if (prime[i])
			{
				/*check the multiple of i * j if present the make element with zero*/
				for (j=i;i*j<num;j++)
				{
					/*Instead of deleteing,making elemnets 0*/
					prime[i*j]=0;
				}
			}
		}
		printf("Sieve of Eratosthenes Prime Series is:\n");
		for(i = 2;i <= num -1;i++)
		{
			/*check if 0 element is present in array doesn't print 0 only primw number print*/
			if(prime[i])
				printf("%d ",prime[i]);
		}
		printf("\n");
		printf("Do you want to continue(y/n):\n");
		scanf("%s",&ch);
		if (ch =='Y' || ch == 'y')
			continue;
		else if(ch == 'N' || ch == 'n')
			exit(3);
		else
		{
			printf("wrong input\n");
			exit(4);
		}


	}while(1);

}
