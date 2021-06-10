/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP to concatenate two files 
Date:28-May-2019
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*function prototype*/
int option;
FILE *fp,*fp2,*fp3;
int ch,ch2;

void copy_file(FILE *fp1,FILE *fp2);

int main(int argc,char *argv[])
{
	if (argc > 4)
	{
		printf("Error!!!! only 2 files \n");
		exit(1);
	}
	printf("Select a Function\n1.Command line string pass\n2.Command line two file pass and print stdout\n3.concate two files data in third file\nSelect a option\n");
	scanf("%d",&option);
	switch (option)
	{
		case 1:
			copy_file(stdin,stdout);

			break;
		case 2:
			fp = fopen(argv[1],"r");
			fp2 = fopen(argv[2],"r");

			if(fp == NULL)
			{
				printf("file1 not exits\n");
				exit(1);
			}
			else if(fp2 == NULL)
			{
				printf("file2 not exits\n");
				exit(2);
			}

			copy_file(fp,stdout);
			copy_file(fp2,stdout);
		
		/*	while((ch = getc(fp)) != EOF)
			{
				putc(ch,stdout);
			}
			while((ch = getc(fp2)) != EOF)
			{
				putc(ch,stdout);
			}*/
			break;
		case 3:
			fp = fopen(argv[1],"r");
			fp2 = fopen(argv[2],"r");
			fp3 = fopen(argv[3],"a+");
			if(fp == NULL)
			{
				printf("file1 not exits\n");
				exit(1);
			}
			else if(fp2 == NULL)
			{
				printf("file2 not exits\n");
				exit(2);
			}

			copy_file(fp,fp3);
			copy_file(fp2,fp3);
			/*
			while((ch = getc(fp)) != EOF)
			{
				putc(ch,fp3);
			}
			while((ch = getc(fp2)) != EOF)
			{
				putc(ch,fp3);
			}
			*/
			fclose(fp);
			fclose(fp2);
			fclose(fp3);

			break;
		default:
			break;
	}
	return 0;

}
void copy_file(FILE *fp1,FILE *fp2)
{
	int ch;
	while(!feof(fp1))
	{
		ch = fgetc(fp1);
		fputc(ch,fp2);
	}
}
