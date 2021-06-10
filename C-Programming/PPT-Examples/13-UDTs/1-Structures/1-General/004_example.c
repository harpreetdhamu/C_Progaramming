#include <stdio.h>

struct Student
{
	int id;
	char name[20];
	char address[60];
};

int main()
{
	//struct Student s1 = {10, "Tingu", "Bangalore"};
	struct Student s2 = {.name = "chanchal",.address = "MG Road",.id = 10}; 
//printf("id = %d\nname = %s\naddress = %s\n",s1.id,s1.name,s1.address);
printf("id = %d\nname = %s\naddress = %s\n",s2.id,s2.name,s2.address);
//printf("nname = %s\n",s2.name);
	return 0;
}
