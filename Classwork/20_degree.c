#include<stdio.h>
#include<math.h>
double F,C;
double	Temp(double);
int main()
{
	printf("Enter a Farenhiet\n");
	scanf("%lf",&F);
	C = Temp(F);
printf("Farenhiet to Celcius is: %lf\n ",C);
//return y ;
}

double	Temp(double F)
{
double C =0;
C = ((double)5/9 * (F - 32));
	return C;
}
