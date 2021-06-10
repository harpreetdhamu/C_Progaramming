#include <stdio.h>

struct Student
{
	int id;
	char name[20];
	char address[60];
};

int main()
{
	struct Student s1 = {10, "Tingu", "Bangalore"};

	printf("Struture starts at %zu\n", &s1);
	printf("Member id is at %zu\n", &s1.id);
	printf("Member name is at %zu\n", s1.name);
	printf("Member address is at %zu\n", s1.address);

	return 0;
}
