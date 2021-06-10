/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap given the number from 1 to 365, wap to find which day of the year 
Date:07-May-2019
 */


#include <stdio.h>
#include <stdlib.h>

int num, day, result, option, ch;

int main()
{
	do
	{
		printf("Enter a day number:\n");
		scanf("%d",&day);
		printf("\n");
		
		/*day is greater then 365 shows a message exit the program*/
		if(day > 365)
		{
			printf("Oops!!! enter a valid day between 0-365\n");
			exit(1);
		}

		printf("1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n");
		printf("Enter the option to set the first day:\n");
		scanf("%d",&num);
		
		/* option number is greater than 7 then exit the program */
		if(num > 7)
		{
			printf("sorry,please enter a valid number\n");
			exit(1);
		}
		
		/*day number modulus by days in week and reminder is add with entered option first day subtract by 1 and result store in result variable*/
		result=day % 7 + num - 1;
		
		/*result is modulus by 7 and reminder is store in option variable */
		option=result % 7;
		
		//option=result ;
		switch (option)
		{
			case 1:
				printf("The day %d is sunday\n",day);
				break;
			case 2:
				printf("The day %d is monday\n",day);
				break;
			case 3:
				printf("The day %d is tuesday\n",day);
				break;
			case 4:
				printf("The day %d is wednesday\n",day);
				break;
			case 5:
				printf("The day %d is thursday\n",day);
				break;
			case 6:
				printf("The day %d is friday\n",day);
				break;
			case 7:
				printf("The day %d is saturday\n",day);
				break;
			default:
				printf("The day %d is saturday\n",day);
				break;
		}
		printf("Do you want to continue (y/n)\n");
		scanf("%ls",&ch);
		if(ch == 'Y' || ch == 'y')
		{
			continue;
		}
		else if (ch == 'N' || ch == 'n')
		{
			exit(1);
		}
		else
		{
			printf("Wrong input\n");
			exit(1);
		}


	}while(1);
}
