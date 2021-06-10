/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP to Implement your own c-type library (any four)
1 - isalpha == checks for an alphanumeric character
2 - isalnum == checks for an alphabetic character; in the standard "C" locale, it is equivalent to (isupper(c) || islower(c))
3 - isascii == checks whether c is a 7-bit unsigned char value that fits into the ASCII character set
4 - isblank == checks for a blank character; that is, a space or a tab
Date:14-May-2019
 */

/*Function for checks for an alphabetic character*/
int isalpha(int Ch)
{
	if ((Ch >= 'a' && Ch <= 'z')||(Ch >= 'A' && Ch <= 'Z'))
		return 0;
	else
		return 1;
}
/*Function for checks for an alpha_Numeric character*/
int isalnum(int Ch)
{
	if ((Ch >= 'a' && Ch <= 'z')||(Ch >= 'A' && Ch <= 'Z')||(Ch >= '0' && Ch <= '9'))
		return 0;
	else
		return 1;
}
/*Function for checks for an Ascii Caracter*/
char is_ascii(char Ch)
{
	if (Ch >= 33 && Ch <= 127)
		return 0;
	else
		return 1;
}
/*Function for checks for Blank character*/
int isblank(int Ch)
{
	if ((Ch == 32)||(Ch == 9))
		return 0;
	else
		return 1;
}
