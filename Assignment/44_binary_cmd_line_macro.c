/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP to implement binary search for all basic datatypes. 
Date:28-May-2019
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*function to scan the element of array*/
#define SCAN_ARRAY(type_specifier,data_type)					\
{       	                                    		        \
	for(i=0;i<size;i++)										    \
	{												 			\
		printf("array[%i] = ",i);								\
		scanf(#type_specifier,(data_type *)array + i);		\
		getchar();\
	}															\
	printf("\n");												\
}


/*check the if array index 1 is greater than array index 2  then swap the position and sorted the array in ascending order */
#define SORT(data_type)														\
{																			\
	for(i=0;i<size-1;i++)													\
	{																		\
		for(j=0;j<size-1;j++)												\
		{																	\
			if(*((data_type*)array + j) > *((data_type*)array + j + 1))		\
			{																\
				data_type temp= *((data_type*)array + j);						\
				*((data_type*)array + j) = *((data_type*)array + j + 1);	\
				*((data_type*)array + j + 1) = temp;							\
			}																\
		}																	\
	}																		\
}											

#define PRINT(type_specifier,data_type)					\
{       	                                    		        \
	for(i=0;i<size;i++)										    \
	{												 			\
		printf(#type_specifier ",",*((data_type *)array + i));		\
	}															\
	printf("\n");												\
}


/*function to search the whole array*/
#define BINARY(data_type,type_specifier,type_specifier1)										\
{																				\
	int low = 0,mid;															\
	int up = size -1;															\
	do																			\
	{																			\
		mid = (low + up)/2;														\
		if(*(data_type *)item > *((data_type *)array + mid))					\
		low = mid + 1;														\
		if(*(data_type *)item < *((data_type *)array + mid))					\
		up = mid - 1;														\
		\
	}while(low <= up && *(data_type *)item != *((data_type *)array + mid));		\
	if(*(data_type *)item == *((data_type *)array + mid))						\
	printf(#type_specifier" found at position "#type_specifier1"\n",*(data_type *)item,mid+1);			\
	else																		\
	printf(#type_specifier"  not found in array\n",*(data_type *)item);					\
}

void sort_array(void *array,int size,int option);
void binary_search(void *array, int size, char *target);
int size,i,j,option;
char ch;
int main(int argc,char *argv[])
{
	void *array, *item;

	size = atoi(argv[1]);

	printf("Select the type of data\n1. Int\n2. Char\n3. Float\n4. Double\n5. String\nSelect a Option\n");
	scanf("%d",&option);
	getchar();
	switch (option)
	{
		case 1: 
			array = malloc(sizeof(int) * size);
			item =(void*)malloc(sizeof(int));
			printf("Enter a Element of array:\n");
			SCAN_ARRAY(%d,int);
			SORT(int);
			printf("Sorted Array is\n");
			PRINT(%d,int); 
			printf("Enter the item you want to search:\n");
			scanf("%d",(int*)item);
			BINARY(int,%d,%d);										
			break;
		case 2:
			array = malloc(sizeof(char) * size);
			item =(void*)malloc(sizeof(char));
			printf("Enter a Element of array:\n");
			SCAN_ARRAY(%c,char);
			SORT(char);
			printf("Sorted Array is\n");
			PRINT(%c,char); 
			printf("Enter the item you want to search:\n");
			scanf("%c",(char*)item);
			getchar();
			BINARY(char,%c,%d);										
			break;

		case 3:
			array = malloc(sizeof(float) * size);
			item =(void*)malloc(sizeof(float));
			printf("Enter a Element of array:\n");
			SCAN_ARRAY(%f,float);
			SORT(float);
			printf("Sorted Array is\n");
			PRINT(%f,float); 
			printf("Enter the item you want to search:\n");
			scanf("%f",(float*)item);
			BINARY(float,%f,%d);										
			break;

		case 4:
			array = malloc(sizeof(double) * size);
			item =(void*)malloc(sizeof(double));
			printf("Enter a Element of array:\n");
			SCAN_ARRAY(%lf,double);
			SORT(double);
			printf("Sorted Array is\n");
			PRINT(%lf,double); 
			printf("Enter the item you want to search:\n");
			scanf("%lf",(double*)item);
			BINARY(double,%lf,%d);										
			break;
		case 5:
			array = calloc(30,(sizeof(char)* size));
			item =(void*)malloc(sizeof(char) * 30);
			printf("Enter a Element of array:\n");
			for(i=0;i<size;i++)
			{
				printf("array[%i] = ",i);
				scanf("%[^\n]",((char*)array + i* 30));
				getchar();
			}
			printf("\n");
			printf("Sorted Array is\n");
			sort_array(array,size,option);
			for(i=0;i<size;i++)
			{
				printf("%s,",((char*)array + i * 30));
			}
			printf("\n");

			printf("Enter the item you want to search:\n");
			scanf("%[^\n]",(char*)item);
			binary_search(array,size,item);
			break;
		default:
			break;
	}

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

/*check the if array index 1 is greater than array index 2  then swap the position and sorted the array in ascending order */
void sort_array(void *array,int size,int option)
{
	char temp[30];
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
}
