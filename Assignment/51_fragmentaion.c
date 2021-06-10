/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap to fragmentation of array,sort array and find the average of each array.according to highest average swap the position of array using 2d array. 
Date:10-may-2019
 */


#include <stdio.h>
#include <stdlib.h>

int row,col, i ,j ,k ,count = 0;
float **ptr_arr,*temp1,temp,average = 0;
char ch;
int main()
{
	do
	{
		/* enter the row and coloumn */
		printf("Size of Row \n");
		scanf("%d",&row);

		/* This array to store each columns count */
		int array[row];

		/* Memory allocation for rows */
		ptr_arr = malloc(row * sizeof(int *));

		/* Getting the columns values and taking avg also */
		for (i = 0; i < row; i++)
		{
			printf("Enter Row%d Columns:\n",i+1);
			scanf("%d",&col);

			/* Storing each column count in a array also adding 1 */
			array[i] = col + 1;

			/* Memory allocation for columns */
			ptr_arr[i] = malloc(array[i] * sizeof(int));

			printf("Enter a element of array%d:\n",i+1);
			for (j = 0; j < col; j++)
			{
				printf("array[%d] = ",j);
				scanf("%g",&ptr_arr[i][j]);

				/* Taking average of elements */
				average += ptr_arr[i][j];
			}
			average = average / j;

			/* Storing the avg in last block of column */
			ptr_arr[i][j] = average;
			average = 0;
			printf("\n");
		}

		/*Sorting  array*/
		for(i = 0; i < row; i++)
		{
			/* Changing the column position */
			for(j = 0; j < array[i]-1; j++)
			{
				/* Taking one element const and Comparing other elements && we no need to see last element so a[i]-1 */
				for(k = j + 1; k < array[i]-1; k++)
				{
					/* Condition to sort array */
					if(ptr_arr[i][j] > ptr_arr[i][k])
					{
						temp = ptr_arr[i][j];
						ptr_arr[i][j] = ptr_arr[i][k];
						ptr_arr[i][k] = temp;
					}
				}
			}
		}
		printf("before Sorted array is\n");
		for (i = 0; i < row; i++)
		{
			printf("array[%d] = ",i);
			for (j = 0; j < array[i]; j++)
			{
				printf("%g ",ptr_arr[i][j]);
			}
			printf("\n");
		}
		/* Sorting the entire row values based on the last element (avg) in each row */

		for(i = 0;i < row-1; i++)
		{
			for(k = i+1; k < row; k++)
			{
				/* Condition to check each row last element */
				if(*(ptr_arr[i] + array[i] + 1) > *(ptr_arr[k] + array[k] + 1))
				{
				/*	temp1 = ptr_arr[i];
					ptr_arr[i] = ptr_arr[k];
					ptr_arr[k] = temp1;
*/
#if 1
					/* Taking one tmp arr[] */
					temp1 = calloc (array[i], sizeof(int));
					for (j = 0; j < array[i]; j++)
					{
						temp1[j] = ptr_arr[i][j];
						count++;
					}

					/* Based on the size of another row we need to reallocate memory for the row */
					ptr_arr[i] = realloc (ptr_arr[i], array[k]);

					/* Copying one row values to another row*/
					for (j = 0; j < array[k]; j++)
					{
						ptr_arr[i][j] = ptr_arr[k][j];

						/* Counting the total columns */
						array[i] = j;
					}

					/* Based on the size of tmp arr[] we need to reallocate memory for the row */
					ptr_arr[k] = realloc (ptr_arr[k], count);

					/* Copying tmp elements to one another */
					for (j = 0; j < count; j++)
					{
						ptr_arr[k][j] = temp1[j];

						/* Counting the total columns */
						array[k] = j;
					}
					/* Making count 0 in order to sort another rows */
					count = 0;

#endif
				}
			}
		}

		/* Printing the sorted array */
		printf("after Sorted array is\n");
		for (i = 0; i < row; i++)
		{
			printf("array[%d] = ",i);
			for (j = 0; j < array[i]; j++)
			{
				printf("%g ",ptr_arr[i][j]);
			}
			printf("\n");
		}

		printf("\n");
		printf("Do you want to continue (Y/N):\n");
		scanf("%s",&ch);
		if(ch == 'Y' || ch == 'y')
			continue;
		else if(ch == 'N' || ch == 'n')
			exit(1);
		else
		{
			printf("Wrong Input\n");
			exit(1);
		}

	}while(i);
}

