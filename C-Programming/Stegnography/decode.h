#ifndef DECODE_H
#define DECODE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "colors.h"
#include "types.h" // Contains user defined types

/* 
 * Structure to store information required for
 * encoding secret file to source Image
 * Info about output and intermediate data is
 * also stored
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4
#define MAX_PASS_LENGTH 20

typedef struct _DecodeInfo
{
    /* Source Image info */
    char *src_image_fname;
    FILE *fptr_src_image;
    uint image_capacity;
    uint bits_per_pixel;
    char image_data[MAX_IMAGE_BUF_SIZE];

    /* Password info */
    char *pass_ptr;
    char pass_buf[MAX_PASS_LENGTH];
    uint length_passcode;
    
    /* Secret File Info */
    char decode_fname[MAX_FILE_SUFFIX + 8];
    FILE *fptr_decode;
    char extn_decode_file[MAX_FILE_SUFFIX];
    char decoded_data;
    long size_decode_file;
} DecodeInfo;



/* Read and validate Encode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

void printfile(FILE* fptr);

/* Get File pointers for i/p and o/p files */
Status Open_files(DecodeInfo *decInfo);

/* Decode Magic String */
Status decode_magic_string(const char *magic_string, DecodeInfo *decInfo);

/* Encode secret file extenstion */
Status decode_secret_file_extn(DecodeInfo *decInfo);

/* Encode secret file size */
Status decode_secret_file_size(DecodeInfo *decInfo);

/* Encode secret file data*/
Status decode_secret_file_data(DecodeInfo *decInfo);

Status decode(char *argv[]);

Status decode_passcode_length(DecodeInfo *decInfo);

Status decode_passcode(DecodeInfo *decInfo);

#if 0

/* Perform the encoding */
Status do_encoding(EncodeInfo *encInfo);

/* check capacity */
Status check_capacity(EncodeInfo *encInfo);

/* Get image size */
uint get_image_size_for_bmp(FILE *fptr_image);

/* Get file size */
uint get_file_size(FILE *fptr, long *secret_file_size);

/* Copy bmp image header */
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image);





/* Encode function, which does the real encoding */
Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image);

/* Encode a byte into LSB of image data array */
Status encode_byte_to_lsb(char data, char *image_buffer);

/* Copy remaining image bytes from src to stego image after encoding */
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest);

#endif

#endif
