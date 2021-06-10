#include<stdio.h>
#define SET_BIT(num, pos) (num | (1 << pos))   
#define GET_BIT(num1, pos2) (num1 & (1 << pos2))       
#define CLEAR_BIT(num3,pos3) (num3 ^ (1 << pos3))

int main()
{
printf("%d %d %d\n", SET_BIT(5, 2),  GET_BIT(5,2), CLEAR_BIT(5,2));
return 0;
}
