#include<iostream>
using namespace std;
int findGcd(int a,int b,int *x,int *y){
	if(a==0)
	{
		*x=0;
		*y=1;
		return b;
	}
	int x1,y1;
	int gcd=findGcd(b%a,a,&x1,&y1);
	*x=y1-(b/a)*x1;
	*y=x1;
	return gcd;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int x,y;
		cout<<"gcd of (a,b): "<<findGcd(a,b,&x,&y)<<" ";
		cout<<x<<" "<<y<<endl;
	}
}
