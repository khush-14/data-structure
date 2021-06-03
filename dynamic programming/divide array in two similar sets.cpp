#include<iostream>
using namespace std;
int findMin(bool res[], int n){
	int  mini=100;
	int maximum=0;
	for(int i=0; i<=n; i++)
	{
		if(res[i]==true){
			int first_no=i;
			int second_no=n-i;
			if(first_no>second_no){
		    	if(mini>first_no-second_no)
		    	{
		    		mini=first_no-second_no;
		    		maximum=first_no;
				}
			}
			else
			{
				if(mini>second_no-first_no)
				{
					mini=second_no-first_no;
					maximum=second_no;
				}
			}
		}
		
	}
	return maximum;
}
void subsetSum(int arr[],int n,int sum){
	bool subSet[n+1][sum+1]={false};
	int count=0;
	
	for(int i=0; i<=n; i++)
	subSet[i][0]=true;
	
	for(int j=1; j<=sum; j++)
	subSet[0][j]=false;
	
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=sum; j++)
		{
			
			subSet[i][j]=false;
			if(arr[i-1]<=j)
			{
			    if(subSet[i-1][j-arr[i-1]]==true || subSet[i-1][j]==true)
			    subSet[i][j]=true;
			}
			
			else
			subSet[i][j]=subSet[i-1][j];
		}
	}
	for(int i=0; i<=sum; i++)
	{
		if(subSet[n][i]==true)
		cout<<i<<": 1"<<endl;
		else
		cout<<i<<": 0"<<endl;
	}
	bool res[sum+1];
	for(int i=0; i<=sum; i++){
		res[i]=subSet[n][i];
	}
	cout<<findMin(res,sum);
	
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	int sum=0;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	subsetSum(arr,n,sum);
}
