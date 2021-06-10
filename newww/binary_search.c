
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

#define LENGTH 30

/* FINDMID: find the position of an element in an array using binary search algorithm */
#define FINDMID(choice)\
{\
	int min, max, mid;\
	min = 0; max = size;\
	while (min <= max) {\
		mid = (min + max) / 2;\
		if (*(choice *)key == *((choice *)ary + mid))\
			return mid;\
		if (*(choice *)key > *((choice *)ary + mid))\
			min = mid + 1;\
		if (*(choice *)key < *((choice *)ary + mid))\
			max = mid - 1;\
	}\
}

/* SORT: sort thge array elements in ascending order */
#define SORT(choice)\
{\
	for (int i = 0; i < size; i++) {\
		for (int j = i; j < size; j++) {\
			if (*((choice *)ary + i) > *((choice *)ary + j))\
				swap((choice *)ary + i, (choice *)ary + j, type);\
		}\
	}\
}

void swap (void *n1, void *n2, int type)
{
	char temp;
	for (int i = 0; i < type; i++) {
		temp = *((char *)n1 + i);
		*((char *)n1 + i) = *((char *)n2 + i);
		*((char *)n2 + i) = temp;
	}
}

/* BinSearch: find the middle element using FINDMID macro */
int BinSearch(void* ary, int size, void *key, int choice)
{
	if (choice == 1) {
		FINDMID(int);
	} else if (choice == 2) {
		FINDMID(char);
//		printf("key : %c\n", *(char *)key);
	} else if (choice == 3) {
		FINDMID(float);
	} else if (choice == 4) {
		FINDMID(double);
	}
}

/* sort_ary: sort the array elements with the help of macro SORT */
void sort_ary(void *ary, int size, int choice, int type)
{
	if (choice == 1) {
		SORT(int);
	} else if (choice == 2) {
		SORT(char);
//		printf("type : %d, choice : %d\n", type, choice);
	} else if (choice == 3) {
		SORT(float);
	} else if (choice == 4) {
		SORT(double);
	}
}


int main(int argc, char* argv[])
{
	int choice, size, type = 1;
	void* ary;
	void *key;

/* Get the length of array through command line */
	if (!argv[1]) {
		printf("error: ./a.out 4\n");
		return 0;
	} else
		size = atoi(argv[1]);

/* let user choose the type */
	printf("Choose the type for elements\n");
	printf("1. int\n2. char\n3. float\n4. double\n5. String\nYour choice : ");
	scanf("%d", &choice);
	if (choice == 1 || choice == 3)
		type = 4;
	else if (choice == 4)
		type = 8;

	printf("type : %d\n", type);

/* Allocate the memory */
	if (choice == 1) {
		ary = malloc(sizeof(int) * size);
		key = (void *)malloc(sizeof(int));
		printf("malloc(int)");
	} else if (choice == 2) {
		ary = malloc(sizeof(char) * size);
		key = (void *)malloc(sizeof(char));
		printf("malloc(char)");
	} else if (choice == 3) {
		ary = malloc(sizeof(float) * size);
		key = (void *)malloc(sizeof(float));
		printf("malloc(float)");
	} else if (choice == 4) {
		ary = malloc(sizeof(double) * size);
		key = (void *)malloc(sizeof(double));
		printf("malloc(double)");
	} else if (choice == 5) {
		ary = malloc((sizeof(char) + LENGTH) * size);
		key = (void *)malloc(sizeof(char) * LENGTH);
	}
	
/* Get the array elements */
	printf("Enter the %d elements : \n", size);
	if (choice == 1) {
	for (int i = 0; i < size; ++i) {
		printf(BOLDRED "[" RESET "%d" BOLDRED "]" RESET " -> ", i);\
		scanf("%d", (int *)ary + i);
	}
	} else if (choice == 2) {
	for (int i = 0; i < size; ++i) {
		printf(BOLDRED "[" RESET "%d" BOLDRED "]" RESET " -> ", i);\
		scanf("%c", (char *)ary + i), getchar();
	}
	} else if (choice == 3) {
	for (int i = 0; i < size; ++i) {
		printf(BOLDRED "[" RESET "%d" BOLDRED "]" RESET " -> ", i);\
		scanf("%f", (float *)ary + i);
	}
	} else if (choice == 4) {
	for (int i = 0; i < size; ++i) {
		printf(BOLDRED "[" RESET "%d" BOLDRED "]" RESET " -> ", i);\
		scanf("%lf", (double *)ary + i);
	}
	}

/* Get the key element to search */
	printf("Enter the key element to search: ");\
	if (choice == 1)
		scanf("%d", (int *)key);
	else if (choice == 2) {
		getchar();
		scanf("%c", (char *)key);
	} else if (choice == 3)
		scanf("%f", (float *)key);
	else if (choice == 4)
		scanf("%lf", (double *)key);


/* print the sorted array elements */
	sort_ary(ary, size, choice, type);
	printf("Elements after sorting : \n");
	if (choice == 1) {
		for (int i = 0; i < size; ++i)
			printf(BOLDRED "[" RESET "%d" BOLDRED "]" RESET " -> %d\n", i, *((int *)ary + i));
	} else if (choice == 2) {
		for (int i = 0; i < size; ++i)
			printf(BOLDRED "[" RESET "%d" BOLDRED "]" RESET " -> %c\n", i, *((char *)ary + i));
	} else if (choice == 3) { 
		for (int i = 0; i < size; ++i)
			printf(BOLDRED "[" RESET "%d" BOLDRED "]" RESET " -> %.2f\n", i, *((float *)ary + i));
	} else if (choice == 4) {
		for (int i = 0; i < size; ++i) 
			printf(BOLDRED "[" RESET "%d" BOLDRED "]" RESET " -> %.2lf\n", i, *((double *)ary + i));
	}

/* print the position of the key element */
	if (choice == 1)
		printf("The element %d is at position %d\n", *(int *)key, BinSearch(ary, size, key, choice));
	else if (choice == 2)
		printf("The element %c is at position %d\n", *(char *)key, BinSearch(ary, size, key, choice));
	else if (choice == 3)
		printf("The element %.2f is at position %d\n", *(float *)key, BinSearch(ary, size, key, choice));
	else if (choice == 4)
		printf("The element %.2lf is at position %d\n", *(double *)key, BinSearch(ary, size, key, choice));

	free(ary);
	free(key);
	return 0;
}




/*
#define GETELEMENTS(specifier, choice)\
{\
	for (int i = 0; i < size; ++i) {\
		printf(BOLDRED "[" RESET "specifier" BOLDRED "]" RESET " -> ", i+1);\
		scanf("specifier", (choice *)ary + i);\
	}\
}

#define PRINTELEMENTS(specifier, choice)\
{\
	for (int i = 0; i < size; ++i) {\
		printf(BOLDRED "[" RESET "specifier" BOLDRED "]" RESET " -> specifier\n", i+1, *((choice *)ary+ i));\
	}\
}

#define GETKEY(specifier, choice)\
{\
	printf("Enter the element to search: ");\
	scanf("specifier, (choice *)key");\
}
*/



//	char string_key[LENGTH];
//	printf("key : %f\n", *(float *)key);
	
/*	for (int i = 0; i < size; ++i) {		// read key string in case of option chosen is String 
		printf(BOLDRED "[" RESET "%d" BOLDRED"]" RESET " -> ", i+1);
		getchar();
		scanf("%[^\n]s", (char *)ary + i*20);
//		printf("[%d]-> %s\n", i, (char *)ary + i*20);
	}
	printf("Enter the key element to search : ");
	scanf("%s", key2);
*/
