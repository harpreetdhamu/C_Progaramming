
#include <stdio.h>
void func(void);
int main()
{
printf( "%s\n" , func()); // Error, invalid use of a function returning void
return 0;
}
void func(void)
{
char buff[] = "Hello World" ;
//return buff; // some co
}

