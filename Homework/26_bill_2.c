#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int pcs, pcs1, pcs2, pcs3,total_pcs;
float cost, cost1, cost2, cost3,amount, amount1, amount2, amount3,total_amount;
char item[30] ,item1[30], item2[30], item3[30];

int main()
{
	printf("Enter a item1\n");
	//		scanf("%[^\n]",item1);
//fgets(item1, 30, stdin);
scanf("%s%*s",item1);
	getchar();
	printf("Enter a pcs\n");
	scanf("%d",&pcs1);
	printf("Enter a cost\n");
	scanf("%f",&cost1);
	printf("Enter a item2\n");
amount1 = pcs1 * cost1;
//fgets(item2, 30, stdin);
scanf("%s%*s",item2);
	//	scanf("%[^\n]",item2);
	getchar();
	printf("Enter a pcs\n");
	scanf("%d",&pcs2);
	printf("Enter a cost\n");
	scanf("%f",&cost2);
amount2 = pcs2* cost2;
total_amount = amount1 + amount2;
total_pcs = pcs1 + pcs2;
printf("-------------------------------------------------------------------------\n");
printf("S.No\t Name\t\tQuantity\t\tCost\t\t Amount\n");
printf("-------------------------------------------------------------------------\n");
printf("%-2d   %s\t\t %2d\t\t %8.2f\t\t %8.2f\n",1,item1, pcs1, cost1, amount1 );
printf("%-2d   %s\t\t %2d\t\t %8.2f\t\t %8.2f\n",2,item2, pcs2, cost2, amount2 );
printf("-------------------------------------------------------------------------\n");
printf("Total\t\t\t %d\t\t\t\t\t%8.2f\n\n",total_pcs,total_amount );
printf("-------------------------------------------------------------------------\n");
//printf("%-2d   %s\t\t %d\t\t %4.2f\t\t %4.2f\n",3,item3, pcs3, cost3, amount3 );



}
