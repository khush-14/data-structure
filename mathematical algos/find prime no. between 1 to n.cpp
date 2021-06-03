#include<stdio.h>
#include<math.h>

int main()
{
	int i,n,isprime;
	printf("enter the no.");
	scanf("%d",&n);
	int j=0;
	int t=pow(n,0.5);
	for(i=t; i<n; i++)
	{
		if(n%i==0)
		{ j++; 
		printf("%d ",i);
		
		
		}
    }
    if(j==0)
    printf("Yes");
}
/*
long int factors(long int n)
{
    long int j=pow(n,0.5);
    if(n<=3)
    return 0;
    for(long int i=j+1; i<n; i++){
        if(n%i==0){
        return i;}
    }
    if(n%j==0)
    return j;
     
    return 0;

}
int downToZero(long int n) {
    if(n<=0)
    return 0;
    
    long int j=0;
    j=factors(n);
    if(j!=0)
    {
        n=j;
    }
    else
    n=n-1;
    printf("%d\n",n);
    return 1+downToZero(n);
    

}
int main()
{
	long int n;
	scanf("%d",&n);
	int result=downToZero(n);
	printf("%d",result);
}
*/
