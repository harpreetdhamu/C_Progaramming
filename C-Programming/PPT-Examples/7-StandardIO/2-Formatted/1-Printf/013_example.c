#include <stdio.h>
#include <unistd.h>
int main()
{
	int ret;
	char string[] = "Hello World";

	ret = printf("%s\n", string);

	printf("The previous printf() printed %d chars\n", ret);
//close(1);
	return 0;
//	ret = printf("%s\n", string);

//fprintf(stderr,"The previous printf() printed %d chars\n", ret);
//	return 0;
}
