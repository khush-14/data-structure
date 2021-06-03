#include<stdio.h>
int main()
{
	int col,b,i,j,n,c;
	printf("enter no. of rows:");
	scanf("%d",&n);
	c=n;
	for(i=1; i<=n; i++)
	{ 
	for(b=c; b>=1; b-- )

		printf(" ");
	c--;

	j=1;
	for(col=0; col<i; col++)

{
		j=col%2;
		printf("%d",j);
	
}
	printf("\n");
	} 
return 0;	 
}
