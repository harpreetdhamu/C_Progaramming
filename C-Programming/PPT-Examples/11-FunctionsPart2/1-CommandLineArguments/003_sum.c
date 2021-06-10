#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv,char **envp[])
{
int i;
i= atoi(argv[1])+atoi(argv[3]);
printf("%d\n",i);
	return 0;
}
