/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Write an alternative version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2. 
Date:10-may-2019
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int size, i , j,len1, len2,count,k;
char str1[50],str2[50];
void squeez(char *,char *,int,int);/*function Prototype */
int main()
{
	printf("Enter the string 1 \n");
	fgets(str1,50,stdin);
	fflush(stdin);
	printf("Enter the string 2 \n");
	fgets(str2,50,stdin);
	fflush(stdin);
	/*Calculate the length of both string*/
	len1 = strlen(str1);
	len2 = strlen(str2);
	squeez(str1,str2,len1,len2);/*pass the address of both string and both strings length to function squeez */

	//printf("String with squeez:\n");
	//printf("%s\n",str3);
}
/*Function for Remove the characters in string 1 that matches with string 2*/
void squeez(char *str1,char *str2,int len1,int len2)
{
	char str3[50];
	k=0;
	for(i = 0;i < len1;i++)
	{
		int count = 0;
		for(j=0; j< len2;j++)
		{
			if(*(str1 + i) == *(str2 + j))
			{
				count++;
			}
		}
		if(count == 0)
		{
			*(str3 + k) = *(str1 + i);
			k++;
		}
		else
			continue;
	}
	*(str3 + k) = '\0';
	printf("After squeez string is:\n %s\n",str3);
	//return *str3;
}



