#include <stdio.h>
#include <string.h>
char *ptr;
int j;

int main(int argc, char **argv,char **envp[])
{
int i;
	printf("No of argument(s): %d\n", argc);

	printf("List of argument(s):\n");
	for (i = 0; envp[i] != NULL; i++)
	{   
		printf("\t%d - \"%s\"\n", i + 1, envp[i]);
		j=strncmp(envp[i],"dheeraj",7);
		printf("j=%d\n",j);
		if(j==0)
		{
			ptr=envp[i];
			printf("envp found-%s\n",ptr);
		}
	}   

	return 0;
}
