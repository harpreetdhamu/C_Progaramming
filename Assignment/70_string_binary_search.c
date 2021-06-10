/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Read n & n floats in a float array ’store’. Print the values in sorted order without modifying or copying ’store’ 
Date:28-May-2019
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*function to search the whole array*/


void binary_search(void *array, int size, char *target);
//void binary_string(void *array,char *item,int size);                                        
int size,i,j,low,mid,up,option;
char ch;
char temp[50];
int main(int argc,char *argv[])
{
	do
	{
		void *array,*item ;

		size = atoi(argv[1]);

		//array = malloc((sizeof(char) + 50) * size);
		array = calloc(size,sizeof(char) *30);
		item =(void*)malloc(sizeof(char) *30);
		/* Enter the Element of array */
		printf("Enter a Element of array:\n");
		for(i=0;i<size;i++)
		{
			printf("array[%i] = ",i);
			scanf("%s",((char*)array + i* 30));
			getchar();
		}
		printf("\n");

		for (int i = 0 ; i < size ; i++)
		{
			for (int j = 0 ; j < size ; j++)
			{
				/*if both strings are same cmp is 0,if both are same but order is not same,cmp return negative value and if both strings are opposite then smp returns positive value*/
				//printf("Before swapping %s  %s\n", ((char *)ptr_arr + i * 30), ((char *)ptr_arr + j * 30));
				if (strcmp ( ((char *)array+ i * 30), ((char *)array + j * 30) ) < 0)
				{
					/*swapping the string if both string are opposite then swap positions*/
					strcpy (temp, (array + i * 30));
					strcpy ((array + i * 30), (array + j * 30));
					strcpy ((array + j * 30), temp);
				}
			}
		}

		printf("Sorted Array is\n");
		for(i=0;i<size;i++)
		{
			printf("%s,",((char*)array + i * 30));
		}
		printf("\n");

		printf("Enter the item you want to search:\n");
		scanf("%s",(char*)item);

		binary_search(array,size,item);                                        
		//BINARY(char,%s,%d);
		printf("do you want to continue(y/n):\n");
		scanf("%s",&ch);
		getchar();
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
	return 0;
}
/*function to search the whole array*/
void binary_search(void *array, int size, char *target)
{
    int bottom= 0;
    int mid;
    int top = size - 1;

    while(bottom <= top)
		{
        mid = (bottom + top)/2;
        if (strcmp(((char*)array + mid * 30), target) == 0)
		{
            printf("%s found at location %d.\n", target, mid+1);
            return;
        } 
		else if (strcmp(((char*)array + mid * 30), target) > 0)
		{
            top = mid - 1;
        }
		else if (strcmp(((char*)array + mid * 30), target) < 0)
		{
            bottom = mid + 1;
        }
    }
		printf("%s not found in array\n",target);  
}

