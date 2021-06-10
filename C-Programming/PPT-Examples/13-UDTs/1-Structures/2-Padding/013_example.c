#include <stdio.h>
//#pragma pack(1)
struct Student
{
	char ch1;
	short s1;
	float x;
	int num;
	double ch2;
	 long ch3;
};

int main()
{
	struct Student s1;

	printf("%zu\n", sizeof(struct Student));

	return 0;
}
