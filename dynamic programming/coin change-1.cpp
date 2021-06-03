#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int ret_dp(vector<int> coin,int n,int sum){
	int dp[n+1][sum+1]={0};
	for(int j=0; j<=sum; j++)
	dp[0][j]=0;
	for(int i=0; i<=n; i++){
		dp[i][0]=1;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){
			if(j>=coin[i-1]){
				dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
			}
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][sum];
}
int main(){
	int n;
	cin>>n;
	vector<int> coin;
	for(int i=0; i<n; i++){
		int j;
		cin>>j;
		coin.push_back(j);
	}
	int sum;
	cin>>sum;
	cout<<ret_dp(coin,n,sum);
}
