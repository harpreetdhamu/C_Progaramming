#include <stdio.h>
#include <stdlib.h>

struct Student
{	
	int id;
	char *name;
	char *address;
};

struct Student data(void)
{
	struct Student s;

	s.name = (char *) malloc(30 * sizeof(char));
	s.address = (char *) malloc(150 * sizeof(char));
	printf("Enter a string\n");
	scanf("%s %s",s.name,s.address);
	//	printf("%p\n", s.name);

	return s;
}

int main()
{
	struct Student s1;

	s1 = data();
	//	printf("%p\n", s1.name);
	printf("%s %s\n",s1.name,s1.address);

	free(s1.name);
	free(s1.address);
	return 0;
}
