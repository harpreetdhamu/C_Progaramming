#include <stdio.h>
#include <unistd.h>

int main()
{
	char str[1024] = "1";
 setbuf(stdout,NULL);
	while (1)
	{
		printf("%s", str);
		sleep(1);
	}

	return 0;
}
