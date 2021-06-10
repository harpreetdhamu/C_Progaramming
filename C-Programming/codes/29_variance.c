/*
   Author       : Rajarajan R
   Organization : Emertxe
   Title        : Finding the variance of given num using static and dynamic memory allocation
   Date         : 07.06.2019
*/

/*      #####      START       ######       */

#include <stdio.h>
#include <stdlib.h>

int variance( int *a, int n)
{
    int i, tmp, mean = 0;

    for (i = 0;i < n;i++)
    {
    	mean = mean + *(a+i);
    }
     mean = mean / n;

     /* Sorting */
     for ( i = 0; i < n-1; i++ )
     {
     	 if ( *(a+i) > *(a+i+1) )
	 {
	     tmp = *(a+i);
	     *(a+i) = *(a+i+1);
	     *(a+i+1) = tmp;
	 }
     }	     
     
     tmp = 0;
     for (i = 0;i < n;i++)
     {
     	 *(a+i) = mean - *(a+i);
     	 *(a+i) = *(a+i) * *(a+i);
     	 tmp = tmp + *(a+i);
     }

     tmp = tmp / n ;
     return tmp;
    
}

/* Main program */
int main()
{
    int  choice;
    printf("1.Static\n2.Dynamic\nEnter your option:");
    scanf("%d", &choice );
    
    /* Checking static or dynamic */
    switch ( choice )
    {
	case 1 :
	       {
	       	   int n, i;
	         printf("Enter the array size:");
	         scanf("%d", &n);
	         /* static alloacation */
	         int a[n];

	         for (i = 0;i < n;i++)
		 {
		     scanf("%d", &a[i]);
		 }

		 printf("variance is %d\n", variance( a, n));
		 break;
	       }
	case 2 :
	       {
	       	   int i, n, *p;
	         printf("Enter the array size:");
	         scanf("%d", &n);
	          
	         p = malloc( n );
                  
	         for (i = 0;i < n;i++)
		 {
		     scanf("%d", (p+i));
		 }
		 printf("variance is %d\n", variance( p, n));
		 break;
	       }

	default :
		 printf("Invalid option\n");

    }
}

  /*    ####     END        #####      */
