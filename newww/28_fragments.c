/*
Author       : Rajarajan R
Organization : Emertxe
Title        : Using Double pointers shift the array (fragments)
Date         : 11.06.2019
 */
/*     #####      START       #####    */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char re;
	do
	{
		int i, j, k, n, tmp1 = 0, rows, columns, count = 0;
		void **p, *tmp;
		float avg = 0;

		printf("Enter the no of rows:");
		scanf("%d", &rows);

		/* This array to store each columns count */
		int a[rows];

		/* Memory allocation for rows */
		p = malloc ( rows * sizeof(int*) );

		/* Getting the columns values and taking avg also */
		for ( i = 0; i < rows ; i++ )
		{
			printf("Enter rows %d columns:", i+1);
			scanf("%d", &columns);

			/* Storing each column count in a array also adding 1 */
			a[i] = columns + 1 ;

			/* Memory allocation for columns */
			p[i] = malloc ( a[i] * sizeof( int ) );
			printf("Enter the row %d elements:\n", i + 1);

			/* Getting elements from user */
			for ( j = 0 ; j < columns ; j++ )
			{
				printf("p[%d][%d]:", i, j);
				scanf("%d", ( (int*)p[i] + j) );

				/* Taking average of elements */
				avg = avg + *( (int*)p[i] +j);
			}
			avg = (float)avg / j;

			/* Storing the avg in last block of column */
			*( (float*)p[i] + j) = avg;
			avg = 0;
		}

		/* Sorting the array */
		for ( i = 0 ; i < rows ; i++ )
		{
			/* Changing the column position */
			for ( j = 0 ; j < a[i]-1 ; j++ )
			{
				/* Taking one element const and Comparing other elements && we no need to see last element so a[i]-1 */
				for ( k = j+1 ; k < a[i]-1 ; k ++ )
				{
					/* Condition to sort array */
					if ( *( (int*)p[i] +j) > *( (int*)p[i] +k) )
					{
						tmp1                = *( (int*)p[i] +j);
						*( (int*)p[i] +j)   = *( (int*)p[i] +k);
						*( (int*)p[i] +k)   = tmp1             ;
					}
				}
			}
		} 

		/* Sorting the entire row values based on the last element (avg) in each row */
		for ( i = 0; i < rows-1 ; i++ )
		{
			for ( k = i+1; k < rows ; k++ )
			{

				/* Condition to check each row last element */
				if ( *( (float*)p[i] + a[i]-1) > *( (float*)p[k] + a[k]-1) )
				{
					/* Taking one tmp arr[] */
					tmp = calloc( a[i] , sizeof(int) );

					/* Copying one row elements to tmp ar[] */
					for ( j = 0; j < a[i]; j++ )
					{
						if ( j < a[i]-1 )
						{
							*( (int*)tmp +j) = *( (int*)p[i] +j);
						}
						else
						{
							*( (float*)tmp +j) = *( (float*)p[i] +j);
						}
						count++;
					}

					/* Based on the size of another row we need to reallocate memory for the row */
					p[i] = realloc ( p[i], a[k] );

					/* Copying one row values to another row*/
					for ( j = 0; j <= a[k]; j++ )
					{
						if ( j < a[k]-1 )
						{
							*( (int*)p[i] +j) = *( (int*)p[k] +j);
						}
						else
						{
							*( (float*)p[i] +j) = *( (float*)p[k] +j);
						}
						/* Counting the total columns */
						a[i] = j ;
					}

					/* Based on the size of tmp arr[] we need to reallocate memory for the row */
					p[k] = realloc ( p[k], count );

					/* Copying tmp elements to one another */
					for ( j = 0; j <= count; j++ )
					{
						if ( j < count -1  )
						{ 
							*( (int*)p[k] +j) =  *( (int*)tmp +j);
						}
						else
						{
							*( (float*)p[k] +j) = *( (float*)tmp +j);
						}
						/* Counting the total columns */
						a[k] = j;
					}
					/* Making count 0 in order to sort another rows */
					count = 0;
				}
			}
		}

		/* Printing the sorted array */ 
		for ( i = 0 ; i < rows ; i++ )
		{
			printf("Sorted array[%d]\n", i);
			for ( j = 0 ; j < a[i] ; j++ )
			{
				/* Printing int and float separately */
				if ( j < a[i]-1 )
				{
					printf("%d\n", *( ( (int*)p[i] +j) ) );
				}
				else
				{
					printf("avg = %0.2f\n", *( ( (float*)p[i] +j) ) );
				}
			}
		}
		getchar();
		printf("Do you want to continue(y/n):");
		scanf("%c", &re);
	} while ( re == 'y' );
}

/*      #####       END        #####       */
