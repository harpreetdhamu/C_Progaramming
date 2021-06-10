#include <stdio.h>
#include <string.h>


struct Student
{
	int id;
	char name[20];
	char address[60];
};

static struct Student s1;

int main()
{
	struct Student *sptr = &s1;

	sptr->id = 10;
	strcpy(sptr->name,"hello");
	strcpy(sptr->address,"banglore");
//	sptr->name = "hello";
//	sptr->address = "banglore";
	printf("%d\n%s\n%s\n",sptr->id,sptr->address,sptr->name);

	return 0;
}
