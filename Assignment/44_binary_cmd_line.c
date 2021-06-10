/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Read n & n floats in a float array ’store’. Print the values in sorted order without modifying or copying ’store’ 
Date:28-May-2019
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function Prototype
void sort_array(void *array,int size,int option);
void binary_search(void *array, int size, char *target,int option);
void generic_swap(void* p1, void *p2, int size);

//Global variables
int size,i,j,low,mid,up,option;
char ch;
char temp[30];

int main(int argc,char *argv[])
{
	do
	{
		void *array,*item ;

		size = atoi(argv[1]);

		printf("Select the type of data\n1. Int\n2. Char\n3. Float\n4. Double\n5. String\nSelect a Option\n");
		scanf("%d",&option);
		switch (option)
		{
			case 1:
				/*Allocate the dynamically memory of array and search item */
				array = malloc(sizeof(int) * size);
				item  = (void*)malloc(sizeof(int));
				
				/* pass the address of array and pass the value of size and option*/
				sort_array(array,size,option);
				
				printf("Enter the item you want to search:\n");
				scanf("%d",(int*)item); 
				
				/*pass the address of array and item,pass the value of option and size*/
				binary_search(array,size,item,option);                                        
				break;
			case 2:
				/*Allocate the dynamically memory of array and search item */
				array = malloc(sizeof(char) * size);
				item =(void*)malloc(sizeof(char));
				
				/* pass the address of array and pass the value of size and option*/
				sort_array(array,size,option);
				
				printf("Enter the item you want to search:\n");
				scanf("%c",(char*)item);
				
				/*pass the address of array and item,pass the value of option and size*/
				binary_search(array,size,item,option);                                        
				break;
			case 3:
				/*Allocate the dynamically memory of array and search item */
				array = malloc(sizeof(float) * size);
				item =(void*)malloc(sizeof(float));
				
				/* pass the address of array and pass the value of size and option*/
				sort_array(array,size,option);
				
				printf("Enter the item you want to search:\n");
				scanf("%f",(float*)item);
				
				/*pass the address of array and item,pass the value of option and size*/
				binary_search(array,size,item,option);                                        
				break;
			case 4:
				/*Allocate the dynamically memory of array and search item */
				array = malloc(sizeof(double) * size);
				item =(void*)malloc(sizeof(double));
				
				/* pass the address of array and pass the value of size and option*/
				sort_array(array,size,option);
				
				printf("Enter the item you want to search:\n");
				scanf("%lf",(double*)item);
			
				/*pass the address of array and item,pass the value of option and size*/
				binary_search(array,size,item,option);                                        
				break;
			case 5:
				/*Allocate the dynamically memory of array and search item */
				array = calloc(size,sizeof(char) *30);
				item =(void*)malloc(sizeof(char) *30);
				
				/* pass the address of array and pass the value of size and option*/
				sort_array(array,size,option);
				
				printf("Enter the item you want to search:\n");
				scanf("%s",(char*)item);
				
				/*pass the address of array and item,pass the value of option and size*/
				binary_search(array,size,item,option);                                        
				//BINARY(char,%s,%d);
				break;
			default:
				printf("You enter a Wrong Option\n");
				break;
		}
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
		free(array);
		free(item);
	}while(1);
	return 0;
}
/*in this function scan a elements,sort the elements and print the sorted elements */
/*check the if array index 1 is greater than array index 2  then swap the position and sorted the array in ascending order */
void sort_array(void *array,int size,int option)
{
	switch (option)
	{
		case 1:
			/*scan elements of array*/
			printf("Enter a Element of array:\n");
			for(i=0;i<size;i++)
			{
				printf("array[%i] = ",i);
				scanf("%d",((int*)array + i));
				getchar();
			}
			printf("\n");

			/*sort element of  array*/
			for(i=0;i<size-1;i++)
			{
				for(j=0;j<size-1;j++)
				{
					if(*((int*)array + j) > *((int*)array + j+1))
					{
						int temp = *((int*)array + j);
						*((int*)array + j)= *((int*)array + j + 1);
						*((int*)array + j + 1)= temp;
					}
				}
			}
			
			printf("Sorted Array is\n");
			/*printf elements of array*/
			for(i=0;i<size;i++)
			{
				printf("%d,",*((int*)array + i));
			}
			printf("\n");
			break;
		case 2:
			/*scan elements of array*/
			printf("Enter a Element of array:\n");
			for(i=0;i<size;i++)
			{
				printf("array[%i] = ",i);
				scanf("%c",((char*)array + i));
				getchar();
			}
			printf("\n");
			
			/*sort element of  array*/
			for(i=0;i<size-1;i++)
			{
				for(j=0;j<size-1;j++)
				{
					if(*((char*)array + j) > *((char*)array + j + 1))
					{
						//	generic_swap(((char*)array + j),((char*)array + j + 1),sizeof(char));
						char temp = *((char*)array + j);
						*((char*)array + j)= *((char*)array + j + 1);
						*((char*)array + j + 1) = temp;
					}
				}
			}
			printf("Sorted Array is\n");
			
			/*printf elements of array*/
			for(i=0;i<size;i++)
			{
				printf("%c,",*((char*)array + i));
			}
			printf("\n");
			break;
		case 3:
			/*scan elements of array*/
			printf("Enter a Element of array:\n");
			for(i=0;i<size;i++)
			{
				printf("array[%i] = ",i);
				scanf("%f",((float*)array + i));
				getchar();
			}
			printf("\n");
			
			/*sort element of  array*/
			for(i=0;i<size-1;i++)
			{
				for(j=0;j<size-1;j++)
				{
					if(*((float*)array + j) > *((float*)array + j+1))
					{
						//generic_swap(((float*)array + j),((float*)array + j + 1),sizeof(float));
						float temp = *((float*)array + j);
						*((float*)array + j) = *((float*)array + j + 1);
						*((float*)array + j + 1) = temp;
					}
				}
			}
			printf("Sorted Array is\n");
			
			/*printf elements of array*/
			for(i=0;i<size;i++)
			{
				printf("%.2f,",*((float*)array + i));
			}
			printf("\n");
			break;
		case 4:
			printf("Enter a Element of array:\n");
			/*scan elements of array*/
			for(i=0;i<size;i++)
			{
				printf("array[%i] = ",i);
				scanf("%lf",((double*)array + i));
				getchar();
			}
			printf("\n");
			
			/*sort element of  array*/
			for(i=0;i<size-1;i++)
			{
				for(j=0;j<size-1;j++)
				{
					if(*((double*)array + j) > *((double*)array + j+1))
					{
						double temp = *((double*)array + j);
						*((double*)array + j)= *((double*)array + j + 1);
						*((double*)array + j + 1)=temp;
					}
				}
			}
			
			printf("Sorted Array is\n");
			/*printf elements of array*/
			for(i=0;i<size;i++)
			{
				printf("%.2lf,",*((double*)array + i));
			}
			printf("\n");
			break;
		case 5:
			printf("Enter a string:\n");
			/*scan elements of array*/
			for(i=0;i<size;i++)
			{
				printf("array[%i] = ",i);
				scanf("%s",((char*)array + i* 30));
				getchar();
			}
			printf("\n");
			
			/*sort element of  array*/
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
			/*printf elements of array*/
			for(i=0;i<size;i++)
			{
				printf("%s,",((char*)array + i * 30));
			}
			printf("\n");
			break;
		default:
			printf("You enter a Wrong Option\n");
			break;
	}
}
#if 0
void generic_swap(void* p1, void *p2, int size)
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
#endif
/*in this function search the item using binary search method*/
void binary_search(void *array, int size, char *target,int option)
{
	int bottom= 0;
	int mid;
	int top = size - 1;
	switch(option)
	{
		case 1:
			while(bottom <= top)
			{
				mid = (bottom + top)/2;
				if (*((int*)array + mid) == *(int*)target)
				{
					printf("%d found at location %d.\n", *(int*)target, mid+1);
					return;
				} 
				else if (*((int*)array + mid) > *(int*)target) 
				{
					top = mid - 1;
				}
				else if (*((int*)array + mid) <  *(int*)target)
				{
					bottom = mid + 1;
				}
			}
			printf("%d not found in array\n",*(int*)target);  
			break;
		case 2:
			while(bottom <= top)
			{
				mid = (bottom + top)/2;
				if (*((char*)array + mid) == *(char*)target)
				{
					printf("%c found at location %d.\n",*(char*)target, mid+1);
					return;
				} 
				else if (*((char*)array + mid) > *(char*)target) 
				{
					top = mid - 1;
				}
				else if (*((char*)array + mid) <  *(char*)target)
				{
					bottom = mid + 1;
				}
			}
			printf("%c not found in array\n",*(char*)target);  
			break;
		case 3:
			while(bottom <= top)
			{
				mid = (bottom + top)/2;
				if (*((float*)array + mid) == *(float*)target)
				{
					printf("%.2f found at location %d.\n", *(float*)target, mid+1);
					return;
				} 
				else if (*((float*)array + mid) > *(float*)target) 
				{
					top = mid - 1;
				}
				else if (*((float*)array + mid) <  *(float*)target)
				{
					bottom = mid + 1;
				}
			}
			printf("%.2f not found in array\n",*(float*)target);  
			break;
		case 4:
			while(bottom <= top)
			{
				mid = (bottom + top)/2;
				if (*((double*)array + mid) == *(double*)target)
				{
					printf("%.2lf found at location %d.\n", *(double*)target, mid+1);
					return;
				} 
				else if (*((double*)array + mid) > *(double*)target) 
				{
					top = mid - 1;
				}
				else if (*((double*)array + mid) <  *(double*)target)
				{
					bottom = mid + 1;
				}
			}
			printf("%.2lf not found in array\n",*(double*)target);  
			break;
		case 5:
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
			break;
		default:
			printf("You enter a Wrong Option\n");
			break;
	}
}

