/*WAP to print power of two series using for loop
 */

#include<stdio.h>

int Power,Total=1,i;
int main()
{
printf("Emter a Power:\n ");
scanf("%d",&Power);

for(i=0;i<Power;i++)
{

Total=Total*2;
printf("%d,",Total);
}

}
