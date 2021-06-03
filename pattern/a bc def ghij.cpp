#include<stdio.h>
int main()
{
	int a,n,i,j,k;
	char ch='A';
	printf("enter the no. of rows:");
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=i; j++)
		{printf("%c",ch);
		ch++;
		}
	printf("\n");
		
	}
	return 0;
}
