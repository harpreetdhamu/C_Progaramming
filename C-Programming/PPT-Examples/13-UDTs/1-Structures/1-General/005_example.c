struct Student
{
	int id;
	char name[20];
	char address[60];
};

int main()
{
	struct Student s1 = {10, "Tingu", "Bangalore"};
	struct Student s2;

	s2 = s1;
printf("id = %d\nname = %s\naddress = %s\n",s2.id,s2.name,s2.address);

	return 0;
}
