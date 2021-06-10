/*WAP a program to print one line
  
*/

#include<stdio.h>

//int i,j;
int main()
{
int i,j,n,m,sub,temp;
printf("Enter a Number of Line:\n ");
scanf("%d",&n);
printf("Enter a Middle of Line:\n ");
scanf("%d",&m);
	for(i=1;i<=n;i++)
	{
	 if(n%2==0)
	 {
	 printf("\n\nPlease enter a valid  Odd Number of Line\n");
	 break;
	 }
	 else 
	 {
		 if (m%2==0)
	 {
	 printf("\n\nPlease enter a Odd middle Number\n");
	 break;
	 }
	 }

		sub=n-m;
		temp=sub/2;
		{
			if(i<=temp || i>n-temp)

				printf("*");
			else
				printf("$");
		}
	//	printf("\n");
	}
	//return 0;
}
