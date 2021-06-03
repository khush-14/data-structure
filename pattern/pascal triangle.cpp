#include<stdio.h>
int main()
{
	int a,space,row,col,n;
	printf("enter the no. of rows:");
	scanf("%d",&a);
	for(row=0; row<a; row++)
	{
		for(space=0; space<a-row; space++)
		printf(" ");
    n=1;
		for(col=0; col<=row; col++)
		{ printf(" %d",n);
		n=n*(row-col)/(col+1);
		}printf("\n");
		
	}
	return 0;

}
