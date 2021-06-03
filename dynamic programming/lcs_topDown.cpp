#include<iostream>
#include<string.h>
using namespace std;
static int t[1001][1001];
int Lcs(string x,string y,int n,int m)
{
	if(n==0 || m==0)
	return 0;
	if(t[n][m]!=-1){
		return t[n][m];
	}
	else{
	    if(x[n-1]==y[m-1])
     	{
	    	t[n][m]=1+Lcs(x,y,n-1,m-1);
		    return t[n][m];
	    }
	    else
	    {
	    	t[n][m]=max(Lcs(x,y,n-1,m),Lcs(x,y,n,m-1));
			return t[n][m];		
	    }
	}
}
int main(){
	string str1;
	string str2;
	cin>>str1;
	cin>>str2;
	int n=str1.length();
	int m=str2.length();
	memset(t,-1,sizeof(t));
	cout<<Lcs(str1,str2,n,m);
}
