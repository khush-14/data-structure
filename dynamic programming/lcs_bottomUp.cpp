#include<iostream>
using namespace std;
int lcsDp(string x,string y,int n,int m){
	int dp[n+1][m+1]={0};
	for(int i=0; i<=n; i++){
		dp[i][0]=0;	
	}
	for(int j=0; j<=m; j++){
		dp[0][j]=0;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(x[i-1]==y[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	string str="         ";
	int count=0;
	int i=n,j=m;
	while(i>0 || j>0){
		if(x[i-1]==y[j-1])
		{
			str[count]=x[i-1];
			i--;
			j--;
			count++;
		}
		else{
			if(dp[i][j]==dp[i-1][j])
			i--;
			else
			j--;
		}
	}
	for(int i=str.length()-1; i>=0; i--){
		if(str[i])
		cout<<str[i];
	}
	return dp[n][m];
}
int main(){
	string x,y;
	cin>>x>>y;
	cout<<lcsDp(x,y,x.length(),y.length());
}
