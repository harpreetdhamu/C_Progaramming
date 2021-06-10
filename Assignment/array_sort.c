#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void main()
{

	char *a[10],dum[10],s;
	int i,k,j,n;
	clrscr();
	printf("enter the no of std....");
	scanf("%d",&n);
	printf("enter the name of students ");
	for(k=0;k<n;k++)
		scanf("%s",a[k]);
	for(i=1;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(strcmp(a[j-1],a[j])>0)
			{
				strcpy(*dum,*a[j-1]);
				strcpy(*a[j-1],*a[j]);
				strcpy(*a[j],*dum);
			}
		} 
	}
	for(i=0;i<n;i++)
		printf("%s",a[i]);

}
