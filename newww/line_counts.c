/* 
 * 
 * Author       :Abhijit
 * Orginazation :Emertxe
 * Title        :To write a program to count number of characters, words and lines, entered through stdin buffer
 * Date         :05/06/2019
 *
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lines = 0, words = 0, characters = 0;
    int c;

    do
    {
        /* Read a character */
        c = getchar();
        /* Increment the character count */
        characters++;
        
        /* If newline increment the line count */
        if (c == '\n')
        {
            lines++;
        }
        
        /* If newline or space or tab increment the word count */
        if (c == ' ' || c == '\n' || c == '\t')
        {
            ++words;
            /* read next character */
            c = getchar();
            
            /* If next character is newline or space or tab decrement the word count */
            if (c == ' ' || c == '\n' || c == '\t')
            {
                words--;
                
            }
            /* unget the character from input stream */
            ungetc(c,stdin);
        }
    
        /* If EOF [ctrl+D] break the loop */
        else if (c == EOF)
        {
            ungetc(c,stdin);
            /* decrement one character count for EOF */
            characters--;
            break;
        }
        
    } while (1);
    
    /* print the character count, word count and line count.*/
    printf("\n");
    printf("Lines = %d\nWords = %d\nCharacters = %d\n", lines, words, characters);
    
    return 0;
    
}
