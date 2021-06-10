#include <stdio.h>

int main()
{
	FILE *fptr;
	char ch; 

	fptr = fopen("file.txt", "a+"); 

	ch = fgetc(fptr);/* This should fail since reading a file in write mode*/
	printf("%d\n",ferror(fptr));
	if (ferror(fptr))
	{
		fprintf(stderr, "Error in reading from file : file.txt\n");
		clearerr(fptr);
	}
	fputs("chanchal singla\n",fptr);
#if 0	/* This loop should be false since we cleared the error indicator */
	if (ferror(fptr))
		fprintf(stderr, "Error in reading from file : file.txt\n");
#endif
	fclose(fptr);

	return 0;
}
