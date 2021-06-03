#include<stdio.h>
int main ()
{
	int a,b,c,n,i;
char	ch='A';
	printf("enter the number of rows:");
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{ 
	for(b=1; b<=i; b++)
{
		printf("%c",ch);
	ch++;
}

		printf("\n");	
	}

	return 0;
}
