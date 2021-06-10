/*author - Vinay J
  organisation - Emertxe
  title - WAP to Read n & n floats in a float store ’store’. Print the values in sorted order without modifying or copying ’store’
  date - 28/05/2019 */

#include <stdio.h>

void print_order (float * store, int n);

int main ()
{	
	char input;
	int n;
	do
	{
		/* number of array elements */
		printf("Enter the number of array elements 'n' : ");
		scanf("%d", &n);
		float store[n], sort[n];
		
		/* accepting the array elements */
		printf("Enter the store elements\n");
		for (int i = 0; i < n ; i++)
		{
			printf("store[%d] = ", i);
			scanf("%f", &store[i]);
		}	
		getchar(); //buffer for enter

		/* sort and print */
		printf("After sorting : "); 
		print_order (store, n); //function call
		
		printf("\nDo u want to continue [y/n] : ");
		scanf("%c", &input);
	} while (input == 'y');	

	return 0;
}

void print_order (float * store, int n)
{
	float min, min1, max;
	min = max = min1 = store[0];

	/* first find min and max out of store-array */
	for(int i = 0; i < n; i++) 
	{
		if(store[i] < min)
			min = store[i];
		if(store[i] > max)
			max = store[i];
	}             

	printf("%g ",min);
	/*find the next min element other than previous */
	while(min != max)
	{
		for(int i = 0; i < n ; i++)
		{
			if(store[i] != min && store[i] > min)     //choose an element greater than already found min and not equal to min itself
			{
				min1 = store[i];
				break;
			}
		}       
		for(int i = 0; i < n ; i++)
		{
			if(store[i] < min1 && store[i] > min)    //with the choosen element in above loop find which is lowest out of store
				min1 = store[i];
		}               
		printf("%g ", min1);
		min = min1;                                   //update min element
	} 
}	
