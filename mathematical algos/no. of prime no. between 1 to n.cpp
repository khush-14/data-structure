#include<stdio.h>
int main()
{
	int i,n,j,c=0;
	scanf("%d",&n);
	for(i=1; i<n; i++)
	{
	
		for(j=2; j<i; j++)
		{
			if(i%j==0)
			{
			c++;
		
			
	}
	
		}
	
		    if(c==0)
	{
			printf("%d,",i);
}

	}
	return 0;
}
