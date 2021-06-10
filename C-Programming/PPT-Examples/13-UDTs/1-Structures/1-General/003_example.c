#include <stdio.h>

struct Student
{
	int id;
	char name[20];
	char address[60];
};

int main()
{
	struct Student s1;

	s1.id= 10;
	strcpy(s1.name,"chanchal");
	strcpy(s1.address,"MG Road Banglore");
printf("id %d\nname %s\naddress %s\n",s1.id,s1.name,s1.address);
	return 0;
}
