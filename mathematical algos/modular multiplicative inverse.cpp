#include<iostream>
using namespacde std;
int find(int a,int m,int *x,int *y){
	if(a==0){
		*x=1;
		*y=0;
		return m;
	}
	int x1,y1;
	int gcd=(m%a,a,&x1,&y1);
	*x=y1-(m/a)*x1;
	*y=x1;
	return gcd;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,m;
		cin>>a>>m;
		int x,y;
		cout<<"value of x is"<<find(a,m,&x,&y)<<endl;
	}
}
