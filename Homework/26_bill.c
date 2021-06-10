#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int pcs, pcs1, pcs2, pcs3;
float cost, cost1, cost2, cost3,amount, amount1, amount2, amount3;
char item[30] ,item1[30], item2[30], item3[30];

int main()
{
	int count=3;
	while(count >=1 )
	{
		printf("Enter a item1\n");
		//		scanf("%[^\n]",item);
		scanf("%s",&item[30]);
		fflush(stdin);
		getchar();
		printf("Enter a pcs\n");
		scanf("%d",&pcs);
		fflush(stdin);
		printf("Enter a cost\n");
		scanf("%2f",&cost);
		fflush(stdin);
		if (count == 1)
		{
			item3[30] = item;
			pcs3 = pcs;
			cost3 =cost;
		}
		else if (count == 2)
		{
			item2[30] = item;
			pcs2 = pcs;
			cost2 =cost;
		}
		else
		{
			item1[30] = item;
			pcs1 = pcs;
			cost1 =cost;
		}
		count--;
	}
	printf("---------------------------------------------------------------------\n");
	printf("S.No\t Name\t\tQuantity\t Cost\t\tAmount\n");
	printf("---------------------------------------------------------------------\n");
	printf("%-2d   %s\t\t %d\t\t %4.2f\t\t %4.2f\n",1,item1, pcs1, cost1, amount1 );
	printf("%-2d   %s\t\t %d\t\t %4.2f\t\t %4.2f\n",2,item2, pcs2, cost2, amount2 );
	printf("%-2d   %s\t\t %d\t\t %4.2f\t\t %4.2f\n",3,item3, pcs3, cost3, amount3 );



}
