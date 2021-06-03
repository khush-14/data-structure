#include<iostream>
using namespace std;
int findGcd(int m,int n){
	if(n==m || n==0 || m==0)
	return m;
	else
	return findGcd(n,m%n);
}
int main(){
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
    	cin>>n>>m;
	    if(m>n)
	    cout<<findGcd(m,n)<<endl;
    	else
	    cout<<findGcd(n,m)<<endl;
    }
}
