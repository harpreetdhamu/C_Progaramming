
#include <stdio.h>
#include <string.h>

/* int to array */
int my_itoa(const char *s, char *s1)
{
    int i = 0, len;
      
     /* Checking for character to store */
     while ( (*(s + i) > 96 && *(s + i) < 123)  ||  ( *(s + i) > 64 && *(s + i) < 123 ) )
     {
         *(s1 + i) = *(s + i);
          i++;
     }

    *(s1+i) = '\0';

    /* Counting the length of string */
    len = strlen( s1 ); 
    return len;
}

/* String to integer foo definition */
int my_atoi( const char *s )
{
     int num = 0, sub = 0;
    
     /* Checking given char have int */
     while ( *s > 47 && *s < 58 )
     {
    	/* Adding 0's to store values orderly */
    	num = num * 10;
     	/* Converting ascii values to decimal values */
    	sub = *s - 48;
    	/* Storing that converted value in a num*/
    	num = num + sub ;
    	*s++;
     }
    return num;
}

/* Function definition for finding the length of strings */
int getword(const char *word)
{
    int count = 0;
    
    while (1)
    {
    	/* Counting the length of string based on condition */
    	if ( *word != '\0')
	{
	    count++;
	    /* Pointer arithmetic shifting to next address */
	    *word++;
	}
	else
	{
	    return count;
	}
    }
    return 0;
}

/* Main function */
int main()
{
   char word[30], s[30], re;
   int choice, len, i = 0, num;
   int *ptr;
do
{

   printf("1. getword\n2. atoi\n3. itoa\nEnter the choice:");
   scanf("%d", &choice);

   /* Condition to select the function */
   switch ( choice )
   {
       case 1 :
                printf("Enter a word:");
                getchar();
                scanf("%[^\n]",word);
                /* Counting the length of given strings */
                len = getword( word );
                printf("Length of %s is %d\n", word, len);
                break;
      case 2 :
                printf("Enter a numeric string:");
                getchar();
                scanf("%[^\n]",word);
                /* Converting given string to int */
                len = my_atoi( word );
                printf("%d\n",len);
                break;
      case 3 :
                printf("Enter a numeric string:");
                getchar();
                scanf("%[^\n]", word);
                /* Converting given int to string */
                len = my_itoa( word, s );
                
                /* Printing the stored strings */
                for(i =0 ; s[i] != '\0'; i++)
		{
		    printf("%c", s[i]);
	}
            
                printf("\nlength is %d\n",len);
                break;
      default : 
      		printf("Invalid choice\n");
   }
 getchar();
 printf("Do you want to continue(y/n):");
 scanf("%c",&re);
 } while ( re == 'y' || re == 'Y');
}
