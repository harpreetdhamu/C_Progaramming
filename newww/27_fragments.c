/* author - Vinay J
   organisation - Emertxe
   title - program to sort different array fragments using mean of the array fragment 
   date - 15/05/2019 */

#include<stdio.h>
#include<stdlib.h>

/* function prototype */
void sort (int size,float *arrayptr);

int main ()
{
	char input;
	int count, size, i, j;
	float sum;

	do
	{
		printf("Enter the numbers of array fragments : ");
		scanf("%d", &count);

		/* declare count number of array of pointers - to point to different array fragments*/
		float *ptr[count];

		/* populate, sort and calculate the mean */
		for (i = 0 ; i < count ; i++)
		{
			sum = 0;
			printf("Enter the size of array fragment-%d : ", i + 1);
			scanf("%d", &size);

			/* allocate memory for each array fragment */
			/* and store the base address in corresponding pointer variable */
			/* first one will be size, last one will be mean */
			ptr[i] = malloc (sizeof(float) * (size + 2));

			printf("allocated memory for ptr[%p] : %ld\n", ptr[i], (sizeof(float) * (size + 2)));

			/* store the size in at the base address */
			*(ptr[i] + 0) = size;

			/* start scanning elements after the size */
			for (j = 1 ; j <= size  ; j++)
			{
				printf("array[%p] : ", (ptr[i] + j));
				scanf("%f", ptr[i] + j);
				sum += *(ptr[i] + j);
			}

			/* sort the array fragment elements */
			/* pass size and base address + 1, since base address stores the size(not be included for sorting) */	
			sort(size, (ptr[i] + 1));	

			/* place the mean at the last memory location of the array fragment */
			*(ptr[i] + j) = sum / size;

			/* terminate the array fragment with a nul character */
			//	*(ptr[i] + j + 1) = '\0';
		}

		/* printing array fragments */	
		printf("array fragments	in memory\n");
		for (i = 0 ; i < count ; i++)
		{
			size = *(ptr[i] + 0);
			//	printf("size : %d\n", size);
			for (j = 0 ; j < size + 2 ; j++)
			{
				printf("%.2f ", *(ptr[i] + j));
			}
			printf("\n");
		}

		/* sorting the array fragments based on the mean */
		printf("Arrangement of array fragments after sorting by mean\n");
		for (i = 0 ; i < count ; i++)
		{
			float *temp;
			//	printf("%f\n", *(ptr[i] + (int)*(ptr[i]) + 1));
			for (j = 0 ; j < count ; j++)
			{
				//		printf("%f\n", *(ptr[j] + (int)*(ptr[j]) +  1));
				/* if mean of fragment1 < fragment2, switch the array fragments */
				if ( *((ptr[j] + (int)*(ptr[j]) + 1)) > *((ptr[i] + (int)*(ptr[i]) + 1)) )
				{
					temp = ptr[i];
					ptr[i] = ptr[j];
					ptr[j] = temp;
				}
			}
		}

		/* printing array fragments, after sorting based on mean */	
		for (i = 0 ; i < count ; i++)
		{
			size = *(ptr[i] + 0);
			//	printf("size : %f\n", *(ptr[i] + 0));
			for (j = 1 ; j < size ; j++)
			{
				printf("%.2f ", *(ptr[i] + j));
			}
			printf("%.2f ", *(ptr[i] + j));
			printf("\n");
		}
		getchar();
		/* prompt for continue */
		printf("Do u want to continue [y/n] : ");
		scanf("%c", &input);
	} while ( input == 'y' );
	return 0;
}

/* function to sort the array, accepts size of array and its base address */
void sort (int size,float *arrayptr)
{	
	float temp;
	for (int i = 0; i < size - 1 ; i++)
	{
		for ( int j = 0; j < size - 1 ; j++)
		{
			if ( arrayptr[j] > arrayptr[j + 1] )
			{ 
				temp = arrayptr[j];
				arrayptr[j] = arrayptr[j + 1];
				arrayptr[j + 1] = temp;
			}
		}
	}
}
