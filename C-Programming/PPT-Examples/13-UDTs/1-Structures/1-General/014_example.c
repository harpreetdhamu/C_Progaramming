#include<stdio.h>
struct College
{
	struct Student
	{
		int id;
		char name[20];
		char address[60];
	} student;
	struct
	{
		int id;
		char name[20];
		char address[60];
	}faculty;
};
int main()
{
	struct College member;
	member.student.id = 10;
	member.faculty.id = 20;
	printf("member student id = %d\nmember faculty id = %d\n",member.student.id,member.faculty.id);
}
