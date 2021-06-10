#include "decode.h"
#include "common.h"
#include "types.h"
#include "colors.h"

OperationType check_operation_type(char *argv[])
{
    if (*(*(argv + 1) + 1) == 'e')
        return e_encode;
    else if (*(*(argv + 1) + 1) == 'd')
        return e_decode;
    else
        return e_unsupported;
}

int main(int argc, char *argv[])
{
    OperationType Optype;
    
    if (argv[1] == NULL)
    {
        printf("./lsb_steg: Decoding: ./lsb_steg -d <.bmp_file> [output file]\n");
        return 0;
    }
    
    system("clear");
    printf("\t\t\t\t---------------- STEGANOGRAPHY -------------\n");

    Optype = check_operation_type(argv);
    if (Optype == e_decode)
        decode(argv);
    else {
        printf("INFO: Unspecified Flag\n");
        return e_failure;
    }
    
    getchar();
    return 0;
}

Status decode(char *argv[])
{
    DecodeInfo decInfo;

    printf(BOLDRED "INFO" RESET ":" BOLDGREEN " ## DECODING PROCEDURE STARTED ##\n" RESET);
    
    if (e_failure == read_and_validate_decode_args(argv, &decInfo))
        return e_failure;

    /* open required files */
    printf(BOLDRED "INFO" RESET ": Opening required files\n");
    decInfo.extn_decode_file[0] = '\0';
    Open_files(&decInfo);

    /* decode magic string signature */
    printf(BOLDRED "INFO" RESET ": Decoding Magic String Signature\n");
    if (e_success == decode_magic_string(MAGIC_STRING, &decInfo))
        printf(BOLDRED "INFO" RESET ": " BOLDGREEN "Done" RESET "\n");
    else {
        printf(BOLDRED"INFO" RESET ": " BOLDYELLOW "###     DECODING ABORTED     ###" RESET "\n");
        return e_failure;
    }
    /* decode output file extention */
    printf(BOLDRED "INFO" RESET ": Decoding Output File Extension\n");
    if (e_success == decode_secret_file_extn(&decInfo))
        printf(BOLDRED "INFO" RESET ": " BOLDGREEN "Done" RESET "\n");

    /* check for the output file name */
    if (argv[3] == NULL) {
        strcpy(decInfo.decode_fname, "decoded");
        strncat(decInfo.decode_fname, decInfo.extn_decode_file, MAX_FILE_SUFFIX);
        printf(BOLDRED "INFO" RESET ": Output File not mentioned. Creating "\
                BOLDMAGENTA "%s" RESET " as default\n", decInfo.decode_fname);
    } else
        strcpy(decInfo.decode_fname, argv[3]);
    /* Open output file */
    Open_files(&decInfo);

    /* decode output file size */
    if (e_success == decode_secret_file_size(&decInfo))
        printf(BOLDRED "INFO" RESET ": " BOLDGREEN "Done" RESET "\n");
    
    /* decode output file data */
    if (e_success == decode_secret_file_data(&decInfo))
        printf(BOLDRED "INFO" RESET ": " BOLDGREEN "Done" RESET "\n");
    printf(BOLDRED "INFO" RESET ": " BOLDGREEN "## DECODING DONE SUCCESSFULLY ##" RESET "\n");

    fclose(decInfo.fptr_src_image);
    fclose(decInfo.fptr_decode);
    return 0;
}

void print_bits(void *num)
{
	unsigned char mask = 0x01 << 7;
	int i = 0;
	while(mask) {
		if (i++ % 8 == 0)
			putc(' ', stdout);
		printf("%d", !!(*(unsigned char *)num & mask));
		mask >>= 1;
	}
	putc('\n', stdout);
}

Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    FILE* helptr;
    
    /* Open help_text file */
    if ((helptr = fopen("help.txt", "r")) == NULL) {
        fprintf(stderr, "Error: Failed Opening FIle %s\n", "help.txt");
        return e_failure;
    }

    if (strstr(argv[2], ".bmp") == NULL) {
     //   printfile(helptr);
        return e_failure;
    } else
        decInfo->src_image_fname = argv[2];

    /* if everything is fine return e_success */
    fclose(helptr);
    return e_success;
}

Status Open_files(DecodeInfo *decInfo)
{
    static int count = 0;
    if (!count++) {
//    if (decInfo->fptr_src_image == NULL) { 
        // Src Image file
        decInfo->fptr_src_image = fopen(decInfo->src_image_fname, "r");
        // Do Error handling
        if (decInfo->fptr_src_image == NULL) {
    	    perror("fopen");
    	    fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->src_image_fname);
    	    return e_failure;
        } else
            printf(BOLDRED "INFO" RESET ": Opened" BOLDMAGENTA " %s\n" RESET, decInfo->src_image_fname);
    }
//    else {

    if (decInfo->extn_decode_file[0] != '\0') { 
        // Secret file
        decInfo->fptr_decode = fopen(decInfo->decode_fname, "w");
        // Do Error handling
        if (decInfo->fptr_decode == NULL) {
    	    perror("fopen");
    	    fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->decode_fname);
    	    return e_failure;
        } else {
            printf(BOLDRED "INFO" RESET ": Opened " BOLDMAGENTA "%s" RESET "\n", decInfo->decode_fname);
            printf(BOLDRED "INFO" RESET ": " BOLDGREEN "Done." RESET " Opened all required files\n");
        }
    }
    
    return e_success;
}


Status decode_lsb_to_byte(char* data, char *image_data)
{
    *data = 0;
    for (int i = 0; i < MAX_IMAGE_BUF_SIZE; ++i)
	{
       *data |= (!!(*(image_data + i) & 0X01) << i);
    }

    return e_success;
}

Status decode_magic_string(const char *magic_string, DecodeInfo *decInfo)
{
    fseek(decInfo->fptr_src_image, 54L, SEEK_SET); 
//printf("ftell : %ld\n", ftell(decInfo->fptr_src_image));
    fread(decInfo->image_data, sizeof(decInfo->image_data), 1, decInfo->fptr_src_image);    
    decode_lsb_to_byte(&decInfo->decoded_data, decInfo->image_data);
    if (decInfo->decoded_data == '*') {
        decInfo->decoded_data = '\0';
        return e_success;
    } else if (decInfo->decoded_data == '#') {
        printf("\t\t\t!!" BOLDRED "PASSWORD PROTECTED" RESET "!!\n");
            decode_passcode_length(decInfo);
            decode_passcode(decInfo);
            decInfo->pass_ptr = getpass("ENTER " BOLDRED "PASSWORD" RESET ": ");
        int i = 0;
        while (i < decInfo->length_passcode && \
                *(decInfo->pass_buf + i) == *(decInfo->pass_ptr + i))
            ++i;
        if (i == decInfo->length_passcode) {
            printf(BOLDRED "INFO" RESET ": Password Matched. Continuing Decoding\n");
            return e_success;
        } else {
            printf(BOLDRED "INFO" RESET ": Wrong Password\n"); 
            printf(BOLDRED"INFO" RESET ": " BOLDYELLOW "ABORTING ENCODING PROCEDURE\n" RESET);
            return e_failure;
        }
    }
    else
        return e_failure;
}

Status decode_passcode_length(DecodeInfo *decInfo)
{
    decInfo->length_passcode = 0;
    for (int i = 0; i < sizeof(decInfo->length_passcode); i++)
    {
        fread(decInfo->image_data, sizeof(decInfo->image_data), 1,\
                decInfo->fptr_src_image);
        decode_lsb_to_byte(((char *)(&decInfo->length_passcode) + i), decInfo->image_data);
    }

    return e_success;
}

Status decode_passcode(DecodeInfo *decInfo)
{
    for (int i = 0; i < MAX_PASS_LENGTH; i++)
        decInfo->pass_buf[i] = 0;

    for (int i = 0; i < decInfo->length_passcode; i++)
    {
        fread(decInfo->image_data, sizeof(decInfo->image_data), 1,\
                decInfo->fptr_src_image);
        decode_lsb_to_byte(&decInfo->decoded_data, decInfo->image_data);
        decInfo->pass_buf[i] = decInfo->decoded_data; 
//putchar(decInfo->decoded_data);
    }
}


Status decode_secret_file_extn(DecodeInfo *decInfo)
{
//    printf("ftell : %ld\n", ftell(decInfo->fptr_src_image));
    for (int i = 0; i < MAX_FILE_SUFFIX; ++i)
    {
        decInfo->extn_decode_file[i] = 0;
        fread(decInfo->image_data, sizeof(decInfo->image_data), 1,\
                decInfo->fptr_src_image);
        decode_lsb_to_byte(&decInfo->extn_decode_file[i], decInfo->image_data);
    }
//    printf("ftell : %ld\n", ftell(decInfo->fptr_src_image));
//printf("%s\n", decInfo->extn_decode_file);
    
    return e_success;
}

Status decode_secret_file_size(DecodeInfo *decInfo)
{
//    printf("ftell : %ld\n", ftell(decInfo->fptr_src_image));
    decInfo->size_decode_file = 0;
    printf(BOLDRED "INFO" RESET ": Decoding File Size\n");
    for (int i = 0; i < sizeof(decInfo->size_decode_file); i++)
    {
        fread(decInfo->image_data, sizeof(decInfo->image_data), 1,\
                decInfo->fptr_src_image);
        decode_lsb_to_byte(((char *)(&decInfo->size_decode_file) + i), decInfo->image_data);
    }
//    printf("ftell : %ld\n", ftell(decInfo->fptr_src_image));

    return e_success;
}

Status decode_secret_file_data(DecodeInfo *decInfo)
{
//    printf("ftell : %ld\n", ftell(decInfo->fptr_src_image));
    printf(BOLDRED "INFO" RESET ": Decoding File Data\n");
    for (int i = 0; i < decInfo->size_decode_file; i++)
    {
//    for (int i = 0; i < 5; i++)
        fread(decInfo->image_data, sizeof(decInfo->image_data), 1,\
                decInfo->fptr_src_image);
        decode_lsb_to_byte(&decInfo->decoded_data, decInfo->image_data);
        putc(decInfo->decoded_data, decInfo->fptr_decode);
//putchar(decInfo->decoded_data);
    }
    
    return e_success;
}
