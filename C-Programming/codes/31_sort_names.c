
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 32

/* swap two strings */
void Swap(char *a, char* b)
{
	int i;
	char* temp = (char *)(malloc (sizeof(char ) * 32));
	i = 0;
	while (*(temp + i++) = *(a + i));
	i = 0;
	while (*(a + i++) = *(b + i));
	i = 0;
	while (*(b + i++) = *(temp + i));
}

/* sort names in chronological order */
void sort_names(char *ptr[], int len)
{
	for (int i = 0; i < len-1; ++i)     /* get the ptr of 1st string */
    {
		for (int j = i+1; j < len; ++j) /* get the ptr of 2nd string */
        {
			if (**(ptr + i) == **(ptr +j)) 
            {
                for (int k = 1; '\0' != *(*(ptr + i) + k); k++) /* get characters from i and j */
                {
                    if (*(*(ptr + i) + k) != *(*(ptr + j) + k))
                        if (*(*(ptr + i) + k) > *(*(ptr +j) + k))
                            Swap(*(ptr + i), *(ptr + j));
                }
			}
		    if (**(ptr + i) > **(ptr +j))
				Swap(*(ptr + i), *(ptr + j));
		}
	}
}

int main()
{
	int n;
	printf("Enter total count of strings to be stored : ");
	scanf("%d", &n), getc(stdin);				// reads n

	char *names[n];

    for (int i = 0; i < n; i++)
        names[i] = (char *)malloc(sizeof(char) * MAXLEN);   /* allocate memory */

	printf("Enter the %d names (max 32 characters in each)\n", n);
	for (int i = 0; i < n; i++) {
		printf("%d -> ", i+1);
		scanf("%[^\n]s", *(names + i)), getchar();
	}
	
    sort_names(names, n);
	printf("\n" "SORTED NAMES : \n");
	
    for (int i = 0; i < n; ++i) 		// print n names
		printf("%d %s\n", i+1, *(names + i));
}
