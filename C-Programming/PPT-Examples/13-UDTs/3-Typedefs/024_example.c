#include <stdio.h>

typedef int * int_ptr;
typedef float * float_ptr;
//#define int_ptr int *
//#define float_ptr float *
int main()
{
	int_ptr ptr1, ptr2, ptr3;
	float_ptr fptr;
	printf("ptr1 = %p\nptr2 = %p\nptr3 = %p\nfptr = %p\n",ptr1,ptr2,ptr3,fptr);

	return 0;
}
