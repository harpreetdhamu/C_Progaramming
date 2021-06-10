#include <stdio.h>

// bit returned at location
int bit_return(int a, int loc)   
{
    int Mask = a & 1<<loc;

    if (Mask == 0) return 0;
    else return 1; 
}

int main() 
{
    //11000010111011010100000000000000  
    // 1 sign bit | 8 exponent bit | 23 fraction bits
    float a = -118.625; 
    int *b;
    b=&a;

    int i;
    for (i = 31; i >= 0; i--)
    {
        printf("%d",bit_return(*b,i));
    }
printf("\n");
    return 0;
}
