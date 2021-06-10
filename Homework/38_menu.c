#include<stdio.h>
#include<stdlib.h>
void print_menu(char**);
int main()
{
	int	num;
	char *str[5]={"File","Edit","View","Insert","Help"};

	print_menu(str);
	printf("\n");
}

void print_menu(char **menu)
{
	int i, num;
	for(i = 0;i<=4;i++)
	{
		printf("%d.%s\n",i+1,menu[i]);
	}
	printf("\n");
	printf("Select your option:\n");
	scanf("%d",&num);
	if(num < 1 || num >5)
	{
		printf("Invalid input\n");
			exit(1);
	}
	printf("You have selected %s menu\n",menu[num - 1]);
}
