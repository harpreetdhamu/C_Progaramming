/* 
 * 
 * Author       :Abhijit
 * Orginazation :Emertxe
 * Title        :Print bits of float & double. Check IEEE std.
 * Date         :02/05/2019
 *
 */
#include <stdio.h>
void print_float_bits(int* m)
{
	unsigned int mask;
	int count = 0;

	mask = (1 << (((sizeof(*m)) * 8) - 1));			//mask for extracting each bits from num
	while (mask) {
		//* adding space in sign exponent and mantisa */
		if (count == 1 || count == 9) {
			printf("     ");
		}
		printf("%d", (((mask & *m) != 0) ? 1 : 0));		//prints bits
		++count;
		mask >>= 1;
	}
}

void print_double_bits(long* m)
{
	unsigned long mask;
	int count = 0;

	mask = (1ul << (((sizeof(*m)) * 8) - 1));		//mask for extracting each bits from num
	while (mask) {
		//* adding space in sign exponent and mantisa */
		if (count == 1 || count == 12) {
			printf("    ");
		}
		printf("%d", (((mask & *m) != 0) ? 1 : 0));		//prints bits
		++count;
		mask >>= 1;
	}
}

int main()
{
	float num1;
	double num2;
	int choice;
	char ch;
	do
	{

		printf("Enter you choice :\n");
		printf("1. Float\n2. Double\n");
		printf("Choice : ");
		scanf("%d", &choice);

		if (choice == 1) 
		{
			printf("Enter the float value : ");
			scanf("%f", &num1);

			printf("\nSign  Exponent 		 Mantissa\n");	//print float bits
			print_float_bits((int *) &num1);
//			print_float_bits(&num1);

		}
		else if (choice == 2)
		{
			printf("Enter the double value : ");
			scanf("%lf", &num2);
			printf("\nSign  Exponent   		     Mantissa\n");	//print double bits
			print_double_bits((long *) &num2);
		}
		else
		{
			printf("Invalid choice\n");
		}
		printf("\n");
		printf("Do you want to continue (y/n): ");
		scanf(" %c", &ch);
	}
	while (ch == 'y');
	return 0;
}
