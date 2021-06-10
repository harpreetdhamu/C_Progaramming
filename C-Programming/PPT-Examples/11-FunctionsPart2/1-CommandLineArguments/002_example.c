#include <stdio.h>

int main(int argc, char **argv,char **envp[])
{
int i;
	printf("No of argument(s): %d\n", argc);

	printf("List of argument(s):\n");
	for (i = 0; envp[i] != NULL; i++)
	{   
		printf("\t%d - \"%s\"\n", i + 1, envp[i]);
	}   

	return 0;
}
