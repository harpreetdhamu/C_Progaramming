#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "encode.h"
#include "types.h"
#include "common.h"

int main(int argc,char *argv[])
{
	OperationType Optype;

	if(argv[1] == NULL)
	{
		printf("./lsb_steg: Encoding: ./lsb_steg -e <.bmp_file> <.text_file> [output file]\n");
		printf("./lsb_steg: Decoding: ./lsb_steg -d <.bmp_file> [output file]\n");
		return 0;
	}
	system("clear");

	printf("########\t\t\t\t\tStegnography\n\t\t\t\t\t#########");

	Optype = check_operation_type(argv);
	if(Optype == e_encode)
	{
		encode(argv);
	}
	else
	{
		printf("Info : Unspecified Flag\n");
		return e_failure;
	}
	getchar();
	return 0;
}

/* Check operation type */
OperationType check_operation_type(char *argv[])
{
	if (strcmp(argv[1],"-e") == 0 )
	{
		return e_encode;
	}
	else if (strcmp(argv[1],"-d") == 0 )
	{
		return e_decode;
	}
	return e_unsupported;
}

Status encode(char *argv[])
{
	EncodeInfo encInfo;
	/* check for the right command line arguments */

	if(e_failure == read_and_validate_encode_args(argv, &encInfo))
		return e_failure;
	/* opening required files */
	printf("\nInfo : Opening required files\n");

	if(e_failure == open_files (&encInfo))
		return e_failure;
	else
		printf("Info : done\n");

	printf("INFO : ## ENCODING PROCEDURE STARTED ##  \n");

	/* check for the secret file size */
	printf("INFO : Checking for %s \n",encInfo.secret_fname);

	if (get_file_size(encInfo.fptr_secret, &(encInfo.size_secret_file)))
	{
		printf("INFO : Done. Not Empty\n");
	}
	else
	{
		printf("INFO : Done. File is Empty. Encoding is not possible\n");
		printf("INFO : ABORTING ENCODING PROCEDURE\n");
		printf("INFO : ###      ENCODING ABORTED      ###");
		fclose(encInfo.fptr_src_image);
		fclose(encInfo.fptr_secret);
		fclose(encInfo.fptr_stego_image);
		return e_failure;
	}

	/* Check for .bmp file capacity to keep secret file information */
	printf("INFO : Checking for %s capacity to handle secret.txt\n", encInfo.src_image_fname );

	if (e_success == check_capacity(&encInfo))
	{
		printf("INFO : Done. Found OK\n");
		if(argv[4] == NULL)
			printf("INFO : Output File not mentioned. Creating  steged_img.bmp as default\n");
	}
	else
	{
		printf("INFO : Done. Found NOT OK\n");
		printf("INFO :ABORTING ENCODING PROCEDURE\n");
		sleep(1);
		printf("INFO : ENCODING ABORTED\n" );
		return e_failure;
	}

	/* Copy image header */
	printf("Info : Copying Image Header\n");
	if (e_success == copy_bmp_header(encInfo.fptr_src_image, encInfo.fptr_stego_image))
		printf("INFO : Done\n");
	else
		printf("INFO : Failed\n");
	/* Encode Magic String Signature */
	printf("INFO : Encoding Magic String Signature\n");
	if (e_success == encode_magic_string(MAGIC_STRING, &encInfo))
		printf("INFO : Done\n");
	else
		printf("INFO : Failed\n");

	/* Encode secret file extension */
	printf("INFO : Encoding %s File Extension\n", encInfo.secret_fname);

	/*The strrchr() function returns a pointer to the last occurrence of the character c in the string s.*/
	if (e_success == encode_secret_file_extn(strrchr(encInfo.secret_fname, '.'), &encInfo))
		printf("INFO : Done\n");
	else
		printf("INFO : Failed\n");

	/* Encode secret file size */
	printf("INFO : Encoding %s File Size \n", encInfo.secret_fname);
	if (e_success == encode_secret_file_size(&encInfo))
		printf("INFO : Done \n");
	else
		printf("INFO : Failed \n");

	/* Encode secret file data */
	printf("INFO: Encoding %s File Data\n", encInfo.secret_fname);
	if (e_success == encode_secret_file_data(&encInfo))
		printf("INFO : Done\n");
	else
		printf("INFO :Failed\n");


	/* Copy the left over image data */
	printf("INFO : Copying Left Over Data\n");
	if (e_success == copy_remaining_img_data(encInfo.fptr_src_image, encInfo.fptr_stego_image))
		printf("INFO : Done\n");
	else
		printf("INFO: Failed\n");

	printf("INFO :  ## ENCODING DONE SUCCESSFULLY ##\n");


	fclose(encInfo.fptr_src_image);
	fclose(encInfo.fptr_secret);
	fclose(encInfo.fptr_stego_image);

	return e_success;

}

Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{

	FILE *fp;
	/* Open help_text file */
	if ((fp = fopen("help.txt","r")) == NULL )
	{
		fprintf(stderr,"Error: failed opening file %s\n","help.txt");
		return e_failure;
	}

	if (argv[2] == NULL)
	{
		printfile(fp);
		return e_failure;
	}

	if (strstr(argv[2], ".bmp") == NULL)
	{
		printfile(fp);
		return e_failure;
	}
	else if (argv[3] == NULL)
	{
		printfile(fp);
		return e_failure;
	}
	else
	{
		encInfo->src_image_fname = argv[2];
		encInfo->secret_fname = argv[3];

		/* check for the output file name */
		if(argv[4] == NULL)
		{
			encInfo->stego_image_fname = "steged_beautiful.bmp";
		}
		else
		{
			if (strstr(argv[4], ".bmp") != NULL)
			{
				encInfo->stego_image_fname = argv[4] ;
			}
			else
			{
				printfile(fp);
				return e_failure;
			}

		}

	}
	/* if everything is fine return e_success */
	fclose(fp);
	return e_success;
}

void printfile(FILE *fp)
{
	int ch;
	while((ch = getc(fp)) != EOF)
		putc(ch,stdout);
}

/* Get file size */
uint get_file_size(FILE* fptr,long *size)
{
	/* calculating size */
	for(*size = 0; fgetc(fptr) !=EOF ; ++(*size));
	//	printf("size fpter = %ld\n",*size);
	fseek(fptr,0L,SEEK_SET);
	//	printf("ftell ocurance = %ld\n",ftell(fptr));
	return *size;
}


/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */

uint get_image_size_for_bmp(FILE *fptr_image)
{
	uint width, height;
	// Seek to 18th byte
	fseek(fptr_image, 18, SEEK_SET);

	// Read the width (an int)
	fread(&width, sizeof(int), 1, fptr_image);
	printf("width = %u\n", width);

	// Read the height (an int)
	fread(&height, sizeof(int), 1, fptr_image);
	printf("height = %u\n", height);

	// Return image capacity
	return width * height * 3;
}

/* check capacity */
Status check_capacity(EncodeInfo *encInfo)
{
	encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);
	//printf("image capacity = %d\n",encInfo->image_capacity);
	//printf("secret image capacity = %ld\n",(encInfo->size_secret_file * 8));

	if (encInfo->image_capacity > (encInfo->size_secret_file * 8))
		return e_success;
	else if (encInfo->image_capacity <= (encInfo->size_secret_file * 8))
		return e_failure;
}


/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
	// Src Image file
	encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
	// Do Error handling
	if (encInfo->fptr_src_image == NULL)
	{
		perror("fopen");
		fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

		return e_failure;
	}
	else
	{
		printf("INFO : Opened %s\n", encInfo->src_image_fname);
	}

	// Secret file
	encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
	// Do Error handling
	if (encInfo->fptr_secret == NULL)
	{
		perror("fopen");
		fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

		return e_failure;
	}
	else
	{
		printf("INFO : Opened %s\n", encInfo->secret_fname);
	}

	// Stego Image file
	encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
	// Do Error handling
	if (encInfo->fptr_stego_image == NULL)
	{
		perror("fopen");
		fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

		return e_failure;
	}
	else
	{
		printf("INFO : Opened %s\n", encInfo->stego_image_fname);
	}

	// No failure return e_success
	return e_success;
}


/* Copy bmp image header */
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
	fseek(fptr_src_image, 0L, SEEK_SET);
	int ch;
	for(int i = 0;i < BMP_HEADER_SIZE; i++)
	{
		ch = getc(fptr_src_image);
		putc(ch, fptr_dest_image);
	}
	return e_success;
}

/* Store Magic String */
Status encode_magic_string(const char *magic_string, EncodeInfo *encodeInfo)
{
	fread(encodeInfo->image_data, sizeof(encodeInfo->image_data), 1,encodeInfo->fptr_src_image);	

	printf("magic string = %c\n",*magic_string);	

	encode_byte_to_lsb(*(magic_string + 1), encodeInfo->image_data, encodeInfo->fptr_stego_image);
	return e_success;
}

/* Encode a byte into LSB of image data array */
Status encode_byte_to_lsb(char data, char* image_buffer, FILE* fptr_dest_image)
{
	unsigned char mask = 0x01;
	//	printf("enc_data : %c  %hhx\n", data, data);

	for (int i = 0; i < MAX_IMAGE_BUF_SIZE && mask != 0; i++)
	{
		*(image_buffer + i) &= 0xFE;
		*(image_buffer + i) |= !!(data & mask);
		putc(*(image_buffer + i), fptr_dest_image);
		//	        printf("%ld\n", ftell(fptr_dest_image));
		mask <<= 1;
	}
}

/* Encode secret file extenstion */
Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo)
{
	/*MAX_FILE_SUFFIX = 4*/
	for (int i = 0; i < MAX_FILE_SUFFIX; ++i)
	{
		fread(encInfo->image_data, sizeof(encInfo->image_data), 1, encInfo->fptr_src_image);
		encode_byte_to_lsb(*(file_extn + i), encInfo->image_data, encInfo->fptr_stego_image);
	}

	return e_success;
}

/* Encode secret file size */
Status encode_secret_file_size(EncodeInfo *encInfo)
{
	for (int i = 0; i < sizeof(encInfo->size_secret_file); ++i)
	{
		fread(encInfo->image_data, sizeof(encInfo->image_data), 1, encInfo->fptr_src_image);
		encode_byte_to_lsb(*((char *)(&(encInfo->size_secret_file)) + i), encInfo->image_data, encInfo->fptr_stego_image);
	}   
	return e_success;
}

Status encode_secret_file_data(EncodeInfo *encInfo)
{
	for (int i = 0; i < encInfo->size_secret_file; ++i)
	{
		fread(encInfo->image_data, sizeof(encInfo->image_data), 1,encInfo->fptr_src_image);
		encode_byte_to_lsb(fgetc(encInfo->fptr_secret), encInfo->image_data,encInfo->fptr_stego_image);
	}
	return e_success;
}

/* Copy remaining image bytes from src to stego image after encoding */
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{
	int ch;
	while ((ch = getc(fptr_src)) != EOF)
		putc(*((char *)&ch), fptr_dest);
	return e_success;
}
