/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP to take n and k (1 <= k <= 10) as inputs. Generate consecutive NRPS of length n using k distinct character (0 <= k <= 9) 
Date:21-june-2019
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Function prototype*/
void nprs_str(char *array,int num,int ch);

/*Global Variable*/
int i,j,ch,num;
char option;
int main()
{
	do
	{
		printf("Enter the Length of the string N :\n");
		scanf("%d",&num);
		printf("Enter the number characters C :\n");
		scanf("%d",&ch);
		getchar();

		/*error checking check the character numeber is in range*/
		if ((ch < 1) || (ch > 10))
		{
			printf("Error!! ch not in range. Try again\n");
			exit(1);	
		}


		char array[ch];

		printf("Enter %d distinct characters:\n",ch);
		for(i = 0; i < ch; i++)
		{
			scanf("%c",&array[i]);
			getchar();
		}
		printf("\n");

		/*error checking for entered array is unique or not*/
		for(i = 0 ; i < ch; i++)
		{
			for(j = (i+1);j < ch; j++)
			{
				if(array[j] == array[i])
				{
					printf("Error!! character is not unique\n");
					exit(2);	
				}
			}
		}
		/*pass the array address and pass value of num and character to function nprs_str*/
		nprs_str(array, num, ch);

		printf("Do you want to continue (Y/N):\n");
		scanf("%s",&option);

		if(option == 'Y' || option == 'y')
			continue;
		else if(option == 'N' || option == 'n')
			exit(3);
		else
		{
			printf("Wrong Input\n");
			exit(4);
		}

	}while(1);
	return 0;

}
/*Function to  Generate consecutive NRPS*/
void nprs_str(char *array,int num,int ch)
{
	int count = 0;

	for(int i = 0 ; i < num; i++)
	{
		if( i % ch == 0 && i != 0)
			++count;
		printf("%c",*(array + ( count + i) % ch));
	}
	printf("\n");
}
