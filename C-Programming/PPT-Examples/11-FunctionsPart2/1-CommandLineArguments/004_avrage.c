#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv,char **envp[])
{
	int i,result = 0;
	if (argc < 2)
	{
		printf("Invalid enter Atleast two number \n");
	exit(1);
}
	for(i=1;i < argc; i++)
	{
		result = result+atoi(argv[i]);
	}

	printf("%.2f\n",(float)result/(argc -1));
	return 0;
}

