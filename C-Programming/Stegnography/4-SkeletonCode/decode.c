#include "decode.h"
#include "types.h"
#include "common.h"

int main(int argc,char *argv[])
{
	OperationType Optype;

	if(argv[1] == NULL)
	{
		printf("./lsb_steg: Decoding: ./lsb_steg -d <.bmp_file> [output file]\n");
		return 0;
	}
	system("clear");
	printf("########\t\t\t\t\tStegnography\t\t\t\t\t#########\n");

	Optype = check_operation_type(argv);
	if(Optype == e_decode)
	{
		decode(argv);
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

Status decode(char *argv[])
{
	DecodeInfo decInfo;
	/* check for the right command line arguments */
	printf("INFO : ##### Decoding Procedure Starting ####\n");

	if(e_failure == read_and_validate_decode_args(argv, &decInfo))
		return e_failure;
	/* opening required files */
	printf("\nInfo : Opening required files\n");

	decInfo.extn_decode_file[0] = '\0';
	Open_files(&decInfo);

	/* Decode Magic String Signature */
	printf("INFO : Decoding Magic String Signature\n");
	if (e_success == decode_magic_string(MAGIC_STRING, &decInfo))
		printf("INFO : Done\n");
	else
	{
		printf("INFO : ## Decoding Aborted ##\n");
		return e_failure;
	}

	/* decode output  secret file extension */
	printf("INFO : decoding output File Extension\n");
	if (e_success == decode_secret_file_extn(&decInfo))
		printf("INFO : Done\n");
	else
		printf("INFO : Failed\n");

	/* check for the output file name */
	if (argv[3] == NULL) {
		strcpy(decInfo.decode_fname, "decoded");
		strncat(decInfo.decode_fname, decInfo.extn_decode_file, MAX_FILE_SUFFIX);
		printf("INFO: Output File not mentioned. Creating %s as default\n", decInfo.decode_fname);
	} else
		strcpy(decInfo.decode_fname, argv[3]);
	/* Open output file */
	Open_files(&decInfo);
	/* decode output file size */
	if (e_success == decode_secret_file_size(&decInfo))
		printf("INFO : Done\n");

	/* decode secret file data */
	if (e_success == decode_secret_file_data(&decInfo))
	{
		printf("INFO : Done\n");
		printf("INFO : ## DECODING DONE SUCCESSFULLY ##\n");
	}
	else
		printf("INFO :Failed\n");


	fclose(decInfo.fptr_src_image);
	fclose(decInfo.fptr_decode);

	return 0;

}

Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{

	FILE *fp;
	/* Open help_text file */
	if ((fp = fopen("help.txt","r")) == NULL )
	{
		fprintf(stderr,"Error: failed opening file %s\n","help.txt");
		return e_failure;
	}
	if (strstr(argv[2], ".bmp") == NULL)
	{
		//		printfile(fp);
		return e_failure;
	}
	else
	{
		decInfo->src_image_fname = argv[2];
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

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status Open_files(DecodeInfo *decInfo)
{
	static int count  = 0;
	if(!count++)
	{
		// Src Image file
		decInfo->fptr_src_image = fopen(decInfo->src_image_fname, "r");
		// Do Error handling
		if (decInfo->fptr_src_image == NULL)
		{
			perror("fopen");
			fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->src_image_fname);

			return e_failure;
		}
		else
		{
			printf("INFO : Opened %s\n", decInfo->src_image_fname);
		}
	}
	if (decInfo->extn_decode_file[0] != '\0')
	{
		// Secret file
		decInfo->fptr_decode = fopen(decInfo->decode_fname, "w");
		// Do Error handling
		if (decInfo->fptr_decode == NULL) 
		{
			perror("fopen");
			fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->decode_fname);
			return e_failure;
		}
		else
		{
			printf("INFO : Opened %s\n", decInfo->decode_fname);
			printf("INFO : Done. Opened all required files\n");
		}
	}

	// No failure return e_success
	return e_success;
}


#if 1
/* Store Magic String */
Status decode_magic_string(const char *magic_string, DecodeInfo *decInfo)
{   
	fseek(decInfo->fptr_src_image, 54L, SEEK_SET); 

	//	printf(" magic string =  %c\n",*magic_string);
	printf("ftell : %ld\n", ftell(decInfo->fptr_src_image));
	/*data size image is 8*/
	printf("image data size = %ld\n",sizeof(decInfo->image_data));

	fread(decInfo->image_data, sizeof(decInfo->image_data), 1, decInfo->fptr_src_image);

	//printf("image data =  %s\n",decInfo->image_data);
	//	printf("decoded data =  %d\n",decInfo->decoded_data);
	decode_lsb_to_byte(&decInfo->decoded_data, decInfo->image_data);
	if (decInfo->decoded_data == '*')
	{
		decInfo->decoded_data = '\0'; 
		return e_success;
	} 
	else
		return e_failure;
}
#endif
/* Decode a LSB to byte of image data array */
Status decode_lsb_to_byte(char* data, char* image_data)
{
	//printf("data =  %d\n",*data);
	*data = 0;
	/*MAX_IMAGE_BUF_SIZE = 1 * 8 = 8*/
	for (int i = 0; i < MAX_IMAGE_BUF_SIZE; ++i)
	{
		//	printf("1... image data + i =  %d\n",*(image_data + i));
		*data |= (!!(*(image_data + i) & 0X01) << i);
	}
	return e_success;
}

/* decode secret file extenstion */
Status decode_secret_file_extn(DecodeInfo *decInfo)
{

	/*MAX_FILE_SUFFIX = 4*/
	for (int i = 0; i < MAX_FILE_SUFFIX; ++i)
	{
		decInfo->extn_decode_file[i] = 0;

		fread(decInfo->image_data, sizeof(decInfo->image_data), 1, decInfo->fptr_src_image);
		decode_lsb_to_byte(&decInfo->extn_decode_file[i], decInfo->image_data);

	}

	return e_success;
}

/* decode secret file size */
Status decode_secret_file_size(DecodeInfo *decInfo)
{
	decInfo->size_decode_file = 0;
	printf("INFO: Decoding File Size\n");
	for (int i = 0; i < sizeof(decInfo->size_decode_file); i++)
	{
		//	printf("decode file sizeof(%ld)\n",sizeof(decInfo->size_decode_file));
		//	printf("image data sizeof(%ld)\n",sizeof(decInfo->image_data));
		fread(decInfo->image_data, sizeof(decInfo->image_data), 1,	decInfo->fptr_src_image);
		decode_lsb_to_byte(((char *)(&decInfo->size_decode_file) + i), decInfo->image_data);
	}          
	//	printf("ftell : %ld\n", ftell(decInfo->fptr_src_image));
	return e_success;
}


#if 1
Status decode_secret_file_data(DecodeInfo *decInfo)
{
	printf("ftell = %ld \n",ftell(decInfo->fptr_src_image));
	printf("INFO: Decoding File Data\n");
//printf("size_ decode_file = %ld\n",decInfo->size_decode_file);
//printf("sizeof(%ld) decode file\n",sizeof(decInfo->size_decode_file));
	//for (int i = 0; i < sizeof(decInfo->size_decode_file); i++)
	for (int i = 0; i < decInfo->size_decode_file; i++)
	{
		fread(decInfo->image_data, sizeof(decInfo->image_data), 1, decInfo->fptr_src_image);
		decode_lsb_to_byte(&decInfo->decoded_data, decInfo->image_data);
		putc(decInfo->decoded_data, decInfo->fptr_decode);
	  //printf("ftell : %ld\n", ftell(decInfo->fptr_decode));
	}
	  //printf("ftell : %ld\n", ftell(decInfo->fptr_decode));

	printf("NEW secret\n");
	return e_success;
}
#endif

