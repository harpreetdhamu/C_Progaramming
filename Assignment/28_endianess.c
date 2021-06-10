/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP to check your processor endianess 
Date:27-May-2019
 */


#include <stdio.h>
int main ()
{
  unsigned int num;
  printf("Enter a Number in hex:\n");
  scanf("%x",&num);
  char *c = (char*) &num;
 
  if (*c == (num & 0xff))
  {
	  /*The least significant byte (the "little end") of the data is placed at the byte with the lowest address*/
    printf ("System architecture is little endian = %#x\n",*c);
  }
  else
  {
	  /*The most significant byte (the "big end") of the data is placed at the byte with the lowest address*/
     printf ("System architecture is big endian = %#x \n",*c);
  }
 
  return 0;
}

