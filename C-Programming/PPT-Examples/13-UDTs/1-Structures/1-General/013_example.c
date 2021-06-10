#include<stdio.h>
struct Student
{
	int id;
	char name[20];
	char address[60];
};
int main()
{
	struct Student s[5];
	int i;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &s[i].id);
	}
	for (i = 0; i < 5; i++)
	{
		printf("s[%d].id is %d\n", i, s[i].id);
	}
	for (i = 0; i < 5; i++)
	{
		scanf("%[^\n]", &s[i].name);
	}
	for (i = 0; i < 5; i++)
	{
		printf("s[%d].id is %s\n", i, s[i].name);
	}
	return 0;
}
