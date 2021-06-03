#include<stdio.h>
int main()
{
	int col,b,i,j,n;
	printf("enter no. of rows:");
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{ 
	j=1;
	for(col=1; col<=i; col++)

{
		j=col%2;
		printf("%d",j);
	
}
	printf("\n");
	} 
return 0;	 
}
