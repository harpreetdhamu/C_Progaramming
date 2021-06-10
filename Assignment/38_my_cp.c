/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Implement a my_cp() function 
Date:28-May-2019
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc,char *argv[])
{
	/* Do arg count check */
	if (argc > 3)
	{
		printf("Error!!!! only 2 files \n");
		exit(1);
	}
	FILE *fp,*fp2;
	int ch,ch2;
	fp = fopen(argv[1],"r");
	fp2 = fopen(argv[2],"a+");
 /* check the fopen success or not Open first file in read only mode */
	if(fp == NULL)
	{
		printf("file not exits\n");
		exit(1);
	}

/* Read a character from file.txt till EOF is recieved and copy it to file_copy.txt */
		//for( ;(ch = getc(fp)) != EOF; )
	while((ch = getc(fp)) != EOF)
		{
			putc(ch,fp2);
		}
 /* flush the buffer and close the file*/
	fclose(fp);
	fclose(fp2);
	return 0;

}

