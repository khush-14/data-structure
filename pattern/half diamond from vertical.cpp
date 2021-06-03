#include<stdio.h>
int main ()
{
	int n,p,i,j,k;
	printf("enter the no. :");
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=i; j++)
		printf("*");
	
			printf("\n");
		
	}
		for(i=1; i<=n; i++)
	{
		for(k=n-i; k>=1; k--)
		printf("*");
		
				printf("\n");
	}
	
	
	return 0;
}
