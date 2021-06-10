#include <stdio.h>
#define SWAP(num1,num2, type) \
{                  \
	type temp = num1;   \
	num1 = num2;      \
	num2 = temp;    \
}

int main()
{
	int op;
	printf("Select a data type\n1. int\n2. char\n3. float\n4. double\nSelect a option\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			{
			printf("Enter a number\n");
			int n1,n2;
			scanf("%d %d",&n1,&n2);
			printf("after swapping\n");
			SWAP(n1,n2,int);
			printf("%d %d\n",n1,n2);
			}
			break;
		case 2:
			{
			char n1,n2;
			printf("Enter a number\n");
			scanf("%s %s",&n1,&n2);
			getchar();
			printf("after swapping\n");
			SWAP(n1,n2,char);
			printf("%c %c\n",n1,n2);
			}
			break;
		case 3:
			
			{
				
				printf("Enter a number\n");
			float n1,n2;
			scanf("%f %f",&n1,&n2);
			printf("after swapping\n");
			SWAP(n1,n2,float);
			printf("%f%f\n",n1,n2);
			}
			break;
		case 4:
			{
			printf("Enter a number\n");
			double n1,n2;
			scanf("%lf %lf",&n1,&n2);
			printf("after swapping\n");
			SWAP(n1,n2,double);
			printf("%lf%lf\n",n1,n2);
			}
			break;
		default:
			printf("Wrong Option\n");
			break;
	}
}
