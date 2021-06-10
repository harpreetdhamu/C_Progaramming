#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*Function declarations */
int getword(char *word);
int atoi(char *s);
int itoa(int n,char *s);
int main()
{
	char OPT = 'y';
	do{
	char s1[100],word[100];
	int num,opt,num1;

	
	printf("\nEnter a choice\n1.getword()\n2.atoi()\n3.itoa()\n");
	scanf("%d",&opt);

	switch(opt)
	{
		case 1 :	printf("Enter a string: ");
					getchar();
					scanf("%[^\n]",word);
					getword(word);
					break;


		case 2 :	printf("Enter a string: ");
					getchar();
					scanf("%[^\n]",s1);
					num = atoi(s1);

					printf("The number is %d \n",num);
					break;

		case 3 : 	printf("Enter a number: ");
					scanf("%d",&num1);
					itoa(num1,s1);
					printf("The string is %s \n",s1);
					break;

	}

	printf("Do you want to continue(y/n) : ");
	getchar();
	scanf("%c",&OPT);
	}while(OPT == 'y' || OPT == 'Y');

	return 0;
}

int getword(char *word)
{
	char s1[100];
	char *p1 = s1;
	int count = 0;
	while(*word && isalpha(*word))
	{
		*p1 = *word;
		p1++;
		word++;
		count++;
	}
	printf("You entered %s  \n",s1);
	printf("The length of word  is %d \n",count);

}
int atoi(char *s)
{
	int num = 0;
	char *ptr = s;
	int count = 0;
	while(*s && isdigit(*s))
	{
		count += 1;
		s++;
	}
	s = ptr;
	int mul = pow(10,count - 1);
	while(*s && isdigit(*s))
	{
		int num1 = -(48 - *s);
		num += num1 * mul;
		mul /= 10;

		s++;
	}
	return num;
}

int itoa(int num,char *s)
{
	char *ptr = s;
	while(num != 0)
	{
		*s = (48 + num % 10);
		num = num / 10;
		s++;
	}
	*s = '\0';
	s = ptr;
	for(int i = 0;i<=strlen(s)/2;i++)
	{
		char temp = *(s + i);
		*(s + i ) = *(s + strlen(s) - i - 1);
  		*(s + strlen(s) - i - 1) = temp;
	}
}
