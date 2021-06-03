#include<stdio.h>
int main ()
{
	int a,b,c,n,i,j;
char	ch='A';
	printf("enter the number of rows:");
	scanf("%d",&n);
	a=n;
	for(i=1; i<=n; i++)
	{ 
	
	
	for(b=1; b<=i; b++)
{
		printf("%c",ch);
	ch++;
}
ch='A';
		printf("\n");	
	}

	return 0;
}
