/* 
 * 
 * Author       :Abhijit
 * Orginazation :Emertxe
 * Title        :Print bits of float & double. Check IEEE std.
 * Date         :02/05/2019
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 10

int main(int argc, char* argv[])
{
	int arr[MAX_LEN], count;
	int choice;
	
    if (argv[1] != 0) {
		printf("Select one of the following methods to give inputs\n \
			1. Scan from keyboard.\n \
			2. Proceed with the provided command line arguments\n \
			3. Proceed with environment variable arguments\n \
			Your choice : ");
		scanf("%d", &choice);
		
        if (choice == 2) { 
			count = 0;
			for (int i = 1; argv[i] != 0; ++i) {
				arr[count] = atoi(argv[i]);
				++count; }
		} 
        else if (choice == 1) {
			printf("No. of elements you wanna enter : ");
			scanf("%d", &count);
			printf("Enter the elements : ");
			for (int i = 0; i < count; ++i)
				scanf("%d", &arr[i]);
		} 
        else if (choice == 3) {
            char *p, a[2];
            int len = strlen(p = getenv("ary"));        /* get the elements from env */
            int i = 0, sum = 0;
            a[1] = '\0';
            while(i < len) {
                a[0] = *(p + i++);
                sum += atoi(a);
            }
            printf("Average : %.2f\n", (float)sum / len);   /* find avg */
            return 0;
		} 
        else {
			printf("Invalid input\n");
			return 0;
		}
	} else {
			printf("Select one of the following methods to give inputs\n \
				1. Scan from keyboard.\n \
				2. Proceed with environment variable arguments\n \
				Your choice : ");
			scanf ("%d", &choice);
			
            if (choice == 1) {
				printf("No. of elements you wanna enter : ");
				scanf("%d", &count), getc(stdin);
				printf("Enter the elements : ");
				for (int i = 0; i < count; ++i)
					scanf("%d", &arr[i]);
			}
            else if (choice == 2) {
                char *p, a[2];
                int len = strlen(p = getenv("ary"));        /* get the elements from env */
                int i = 0, sum = 0;
                a[1] = '\0';
                while(i < len) {
                    a[0] = *(p + i++);
                    sum += atoi(a);
                }
                printf("Average : %.2f\n", (float)sum / len);   /* find avg */
                return 0;
		    }
            else {
				printf("Invalid input\n");
				return 0;
			}
		}
	for(int i = 1; i < count; i++) {
		arr[0] += arr[i];
	}
	printf("Average : %.2f\n", (float)arr[0]/count);
	return 0;
}
