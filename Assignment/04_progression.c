/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap to read 3 numbers a, r, n. generate ap, gp, hp 
Date:04-may-2019
 */


#include <stdio.h>
#include <stdlib.h>

int r ,n ,a ,ap = 0,gp = 0, i, firstap, firstgp, firsthp, ch;
float hp = 0.0; 

int main()
{
	do
	{
		printf("Enter a first number (a):\n");
		scanf("%d",&a);
		printf("Enter a difference between first two numbers(r):\n");
		scanf("%d",&r);
		printf("Enter a limit of series(n):\n");
		scanf("%d",&n);

		/* entered number is less than 0 and greater than 1024 then nuber is out of range*/
		if (a < 0 || a >= 1024 || r < 0 || r >= 1024 || n <0 || n >= 1024)
		{
			printf("Opps!!!enter a valid number between 0-1024\n");
			exit(1);
		}
		
		/*an arithmetic progression is a sequence of numbers in which each term is derived from the preceding term by adding a common difference "d"*/		
		printf("Ap series is:\n");
		firstap=a;
		for(i=1;i<=n;i++)
		{
			/*ap=a+(n-1)*d;*/
			printf("%d,",firstap);
			ap = firstap + ap;
			firstap = firstap + r;
		}
		/*printf("%d %d",a,ap);*/
		printf("\n");

		printf("Gp series is:\n");
		firstgp = a;
		for(i=1;i<=n;i++)
		{
			/*a geometric progression is a sequence in which each term is derived by multiplying common ratio*/
			/*	gp=a*r^(n-1);*/
			printf("%d,",firstgp);
			gp = firstgp + gp;
			firstgp = firstgp * r;
		} 
		/*printf("%d %d",a,gp);*/
		printf("\n");
		/* harmonic series is a sequence of terms formed by taking the reciprocals of an arithmetic progression*/	
		printf("Hp series is:\n");
		firsthp = a;
		for(i=1;i<=n;i++)
		{
			/*ap=1/(a+(n-1)*d);*/
			printf("%.3f,",1/(float)firsthp);
			hp = hp + 1 / (float)firsthp;
			firsthp = firsthp + r;
		} 
		/*printf("%d %f",a,hp);*/
		printf("\n");

		printf("Do you want to continue (y/n)\n");
		scanf("%ls",&ch);
		if (ch == 'Y' || ch == 'y')
		{
			continue;
		}
		else if ( ch == 'N' || ch == 'n')
		{
			exit(1);
		}
		else
		{
			printf("wrong key press\n");
			exit(1);
		}
	}while(1);
}

