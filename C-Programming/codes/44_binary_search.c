/* author - Vinay J
   organisation - Emertxe
   title - WAP to implement binary search for all basic datatypes
   date - 15/05/2019 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* function prototypes */
void sort (void);
void generic_swap (void* p1, void *p2, int size);
int binarysearch (void *arr, int l, int r, double x); 
int binarysearch_string (void *arr, int l, int r, char *search);

static void *ptr_arr = NULL;
static int size, choice, i, result, mid;
char input;
double search;

int main (int argc , char **argv)
{
	/* return from program - if array size is not given */
	if (argc < 2)
	{
		printf("Error\nPass the array size through command line\n");
		return 1;
	}

	/* store size */
	size = atoi(argv[1]);
	printf("Size of array is %d\n", size);	

	do
	{
		printf("Choose the type of data\n1. Int\n2. Short\n3. Float\n4. Double\n5. String\nEnter Choice : ");	
		scanf("%d", &choice);

		switch (choice)
		{
			/* choice is int-array */
			case 1 :
				/* dynamic memory allocation */
				printf("Allocating space for a integer array\n");
				ptr_arr = malloc (size * sizeof(int));

				printf("Enter the elements :\n");
				for (i = 0; i < size ; ++i)
				{	
					scanf("%d", ((int *)ptr_arr + i) );
				}
					
				/* sorting function */
				sort();

				/* print the sorted int array */
				printf("Printing the sorted elements :\n");
				for (int i = 0; i < size ; ++i)
				{	
					printf("%d ", *((int *)ptr_arr+ i));
				}
				printf("\n");

				/* calling the binary search */
				printf("Enter the element you want to search for : ");
				scanf("%lg", &search);

				result = binarysearch(ptr_arr, 0 , size - 1, search);

				if (result != -1)
					printf("Element '%lg' is present at index %d\n", search, result);
				else
					printf("Element '%lg' is not present in the array\n", search);

				break;

				/* choice is Short-array */
			case 2 :
				/* dynamic memory allocation */
				printf("Allocating space for a Short array\n");
				ptr_arr = malloc (size * sizeof(short));

				printf("Enter the elements :\n");
				for (i = 0; i < size ; ++i)
				{	
					scanf("%hd", ((short *)ptr_arr + i) );
				}

				/* sorting function */
				sort();

				/* print the sorted short array */
				printf("Printing the sorted elements :\n");
				for (int i = 0; i < size ; ++i)
				{	
					printf("%hd ", *((short *)ptr_arr+ i));
				}
				printf("\n");	

				/* calling the binary search */
				printf("Enter the element you want to search for : ");
				scanf("%lg", &search);

				result = binarysearch(ptr_arr, 0 , size - 1, search);

				if (result != -1)
					printf("Element '%lg' is present at index %d\n", search, result);
				else
					printf("Element '%lg' is not present in the array\n", search);

				break;

				/* choice is Float-array */
			case 3 :
				/* dynamic memory allocation */
				printf("Allocating space for a Float array\n");
				ptr_arr = malloc (size * sizeof(float));

				printf("Enter the elements :\n");
				for (i = 0; i < size ; ++i)
				{	
					scanf("%f", ((float *)ptr_arr + i) );
				}

				/* sorting function */
				sort();

				/* print the sorted float array */
				printf("Printing the sorted elements :\n");
				for (int i = 0; i < size ; ++i)
				{	
					printf("%g ", *((float *)ptr_arr+ i));
				}
				printf("\n");	

				/* calling the binary search */
				printf("Enter the element you want to search for : ");
				scanf("%lg", &search);

				result = binarysearch(ptr_arr, 0 , size - 1, search);

				if (result != -1)
					printf("Element '%lg' is present at index %d\n", search, result);
				else
					printf("Element '%lg' is not present in the array\n", search);

				break;

				/* choice is Double-array */
			case 4 :
				/* dynamic memory allocation */
				printf("Allocating space for a Double array\n");
				ptr_arr = malloc (size * sizeof(double));

				printf("Enter the elements :\n");
				for (i = 0; i < size ; ++i)
				{	
					scanf("%lf", ((double *)ptr_arr + i) );
				}
				
				/* sorting function */
				sort();

				/* print the sorted double array */
				printf("Printing the sorted elements :\n");
				for (int i = 0; i < size ; ++i)
				{	
					printf("%g ", *((double *)ptr_arr+ i));
				}
				printf("\n");	

				/* calling the binary search */
				printf("Enter the element you want to search for : ");
				scanf("%lg", &search);

				result = binarysearch(ptr_arr, 0 , size - 1, search);

				if (result != -1)
					printf("Element '%lg' is present at index %d\n", search, result);
				else
					printf("Element '%lg' is not present in the array\n", search);

				break;

			case 5 :
				/* dynamic memory allocation */
				printf("Allocating space for a string array\n");
				ptr_arr = malloc (size * 30 * sizeof(char));

				printf("Enter the elements :\n");
				for (i = 0; i < size ; ++i)
				{	
					scanf("%s", ((char *)ptr_arr + i * 30));
				}

				/* sorting function */
				sort();

				/* print the sorted string array */
				printf("Printing the sorted elements :\n");
				for (int i = 0; i < size ; ++i)
				{	
					printf("%s ", ((char *)ptr_arr + i * 30));
				}
				printf("\n");	

				{
					char search[30];
					/* calling the binary search */
					printf("Enter the string you want to search for : ");
					scanf("%s", search);

					result = binarysearch_string (ptr_arr, 0 , size - 1, search);

					if (result != -1)
						printf("String \"%s\" is present at index %d\n", search, result);
					else
						printf("String \"%s\" is not present in the array\n", search);
				}
				break;
		}
		free(ptr_arr);
		getchar();
		/* prompt for continue */
		printf("Do u want to continue [y/n] : ");
		scanf("%c", &input);
	} while ( input == 'y' );
	return 0;
}

int binarysearch (void *arr, int l, int r, double x) 
{ 
	switch (choice)
	{
		case 1 :
			while (l <= r)
			{ 
				mid = l + (r - l)  / 2; 
				// Check if x is present at mid 
				if (*((int *)arr + mid) == x) 
					return mid; 
				// If x greater, ignore left half 
				if (*((int *)arr + mid) < x) 
					l = mid + 1; 
				// If x is smaller, ignore right half 
				else
					r = mid - 1;
			}
			// if we reach here, then element was not present 
			return -1; 
			break;	
		case 2 :
			while (l <= r)
			{ 
				mid = l + (r - l) / 2; 
				// Check if x is present at mid 
				if (*((short *)arr + mid) == x) 
					return mid; 
				// If x greater, ignore left half 
				if (*((short *)arr + mid) < x) 
					l = mid + 1; 
				// If x is smaller, ignore right half 
				else
					r = mid - 1;
			}
			// if we reach here, then element was not present 
			return -1; 
			break;	
		case 3 :
			while (l <= r)
			{ 
				mid = l + (r - l) / 2; 
				// Check if x is present at mid 
				if (*((float *)arr + mid) == x) 
					return mid; 
				// If x greater, ignore left half 
				if (*((float *)arr + mid) < x) 
					l = mid + 1; 
				// If x is smaller, ignore right half 
				else
					r = mid - 1;
			}
			// if we reach here, then element was not present 
			return -1; 
			break;	
		case 4 :
			while (l <= r)
			{ 
				mid = l + (r - l) / 2; 
				// Check if x is present at mid 
				if (*((double *)arr + mid) == x) 
					return mid; 
				// If x greater, ignore left half 
				if (*((double *)arr + mid) < x) 
					l = mid + 1; 
				// If x is smaller, ignore right half 
				else
					r = mid - 1;
			}
			// if we reach here, then element was not present 
			return -1; 
			break;	
	} 

}

int binarysearch_string (void *arr, int l, int r, char *search)
{
	int i = 0;	
	while (l <= r)
	{
		mid = l + (r - l) / 2; 
		// Check if string is present at mid 
		//printf("comparing %s %s\n", ((char *)arr + mid * 30), search);
		if (strcmp(((char *)arr + mid * 30), search)  == 0) 
			return mid; 
		// If return value is greater than 0, ignore left half 
		if (strcmp(((char *)arr + mid * 30), search)  < 0) 
		{
			l = mid + 1; 
		}
		// If return value is lesser than 0, ignore right half 
		else
		{
			r = mid - 1;
		}
	}
	// if we reach here, then element was not present 
	return -1; 
}

/* swaps size amount of characters */
void generic_swap (void* p1, void *p2, int size)
{   
	char temp;
	for (int i = 0; i < size; i++)
	{   
		temp = *(char *)p1;
		*(char *)p1 = *(char *)p2;
		*(char *)p2 = temp;
		p1++;
		p2++;
	}   
}

/* function to sort different types */
void sort (void)
{
	/* go to choice */
	switch (choice)
	{
		/* sorting integers */
		case 1 :
			{
				for (int i = 0; i < size - 1; i++)
				{
					for (int j = 0; j < size - 1 ; j++)
					{
						if ( *((int *)ptr_arr + j) > *((int*)ptr_arr + j + 1) )
						{ 
							generic_swap (((int *)ptr_arr + j), ((int*) ptr_arr + j + 1), sizeof(int));
						}
					}
				}
			}
			break;
		case 2 :
		/* sorting short integers */
			{
				for (int i = 0; i < size - 1; i++)
				{
					for (int j = 0; j < size - 1 ; j++)
					{
						if ( *((short *)ptr_arr + j) > *((short *)ptr_arr + j + 1) )
						{ 
							generic_swap (((short *)ptr_arr + j), ((short *) ptr_arr + j + 1), sizeof(short));
						}
					}
				}
			}
			break;
		case 3 :
		/* sorting floats */
			{
				for (int i = 0; i < size - 1; i++)
				{
					for (int j = 0; j < size - 1 ; j++)
					{
						if ( *((float *)ptr_arr + j) > *((float *)ptr_arr + j + 1) )
						{ 
							generic_swap (((float *)ptr_arr + j), ((float *) ptr_arr + j + 1), sizeof(float));
						}
					}
				}
			}
			break;
		case 4 :
		/* sorting doubles */
			{
				for (int i = 0; i < size - 1; i++)
				{
					for (int j = 0; j < size - 1 ; j++)
					{
						if ( *((double *)ptr_arr + j) > *((double *)ptr_arr + j + 1) )
						{ 
							generic_swap (((double *)ptr_arr + j), ((double *) ptr_arr + j + 1), sizeof(double));
						}
					}
				}
			}
			break;
		case 5 :
		/* sorting strings */
			{ 
				char temp[30];
				for (int i = 0 ; i < size ; i++)
				{
					for (int j = 0 ; j < size ; j++)
					{	
						//printf("Before swapping %s  %s\n", ((char *)ptr_arr + i * 30), ((char *)ptr_arr + j * 30));
						if (strcmp ( ((char *)ptr_arr + i * 30), ((char *)ptr_arr + j * 30) ) < 0)
						{
							strcpy (temp, (ptr_arr + i * 30));
							strcpy ((ptr_arr + i * 30), (ptr_arr + j * 30));
							strcpy ((ptr_arr + j * 30), temp);
						}
					}
				}
			}
			break;
	}
}
