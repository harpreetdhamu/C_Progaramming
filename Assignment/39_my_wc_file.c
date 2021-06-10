/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:To read input from file till EOF and print no of wors read. 
Date:18-june-2019
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc,char *argv[])
{
	FILE *fp;
	int ch,word_count = 0;
	
	/* Do arg count check */
	if (argc > 2)
	{
		printf("Error!!!! only 1 files \n");
		exit(1);
	}
	fp = fopen(argv[1],"r");
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
			if(ch == ' ' || ch == '\n')
				++word_count;
		}
	printf("Word Count  = %d\n",word_count);
 /* flush the buffer and close the file*/
	fclose(fp);
	return 0;

}

