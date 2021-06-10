/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Read n & n person names of maxlen 32. Sort and print the names 
Date:10-may-2019
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ch ;
int size, i , j;
void sort_alpha(char (*)[32],int);
int main()
{
	do
	{
		printf("Size of array\n");
		scanf("%d",&size);
		/*two dimenstional array of 32 coloums and row size is input by user*/
		char array[size][32];
		printf("Enter a element of array\n");
		for(i=0;i<size;i++)
		{
			printf("array[%d] = ",i);
			scanf("%s",array[i]);
		}
		printf("\n");

		/*Pass the address and size of 2D array to function sort_alpha*/
		sort_alpha(array,size);
		/*print sorted array in Dictionary order*/
		printf("Sorted array in Dictionary  order\n");
		for(i=0;i<size;i++)
		{
			printf("%d. %s\n",i+1,array[i]);
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

	}while(1);

}
/*Function to sort string in Dictionary order*/
void sort_alpha(char (*array)[32],int size)
{
	char temp[50];
	int cmp;
	for(i=0;i<size;i++)
	{
		for(j=0;j< size - i;j++)
		{
			/*if both strings are same cmp is 0,if both are same but order is not same,cmp return negative value and if both strings are opposite then smp returns positive value*/
			cmp = strcmp(array[j],array[j + 1]);
			/*swapping the string if both string are opposite then swap positions*/
			if(cmp > 0)
			{
				strcpy(temp,array[j]);
				strcpy(array[j],array[j+1]);
				strcpy(array[j+1],temp);
			}
		}
	}
}


