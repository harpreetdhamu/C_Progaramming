#include <stdio.h>

int main()
{
	int num1, num2;
	float num3;
	char str[10], oper, ch;
	FILE *fptr;

	if ((fptr = fopen("text.txt", "w+")) == NULL)
	{   
		fprintf(stderr, "Can't open input file text.txt!\n");
		return 1;
	}   

	fprintf(fptr, "%d %c %d %s %f\n", 2, '+', 1, "is", 1.1);
	
	fseek(fptr, 0L, SEEK_SET);
	printf("\nFile offset is at -> %ld\n", ftell(fptr));
	fscanf(fptr, "%d %c %d %s %f",&num1, &oper, &num2, str, &num3);
	printf("%d %c %d %s %f\n",num1, oper, num2, str, num3);
	
	fseek(fptr, 10L, SEEK_SET);
	printf("\nFile offset is at -> %ld\n", ftell(fptr));
	fscanf(fptr, "%f",&num3);
	printf("%f\n", num3);
	
	fseek(fptr, -16L, SEEK_CUR);
	printf("\nFile offset is at -> %ld\n", ftell(fptr));
	fscanf(fptr, " %c %d %s %f",&oper, &num2, str, &num3);
	printf(" %c %d %s %f\n",oper, num2, str, num3);
	
	fseek(fptr, 3L, SEEK_CUR);
	printf("\nFile offset is at -> %ld\n", ftell(fptr));
	fscanf(fptr, "%s %f",str, &num3);
	printf("%s %f\n",str, num3);

	fseek(fptr,-7L, SEEK_END);
	printf("\nFile offset is at -> %ld\n", ftell(fptr));
	fscanf(fptr, "%f",&num3);
	printf("%f\n",num3);
	
	fclose(fptr);

	return 0;
}
