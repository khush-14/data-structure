#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n;
		int arr[n];
		int sum=0;
		
		for(int i=0; i<n; i++)
		cin>>arr[i];
		
		cout<<"enter value k for max sum of k contigous elements: ";
		cin>>k;
		for(int i=0; i<k; i++)
		sum+=arr[i];
		
		int max=sum;
		int left_index=0;
		int right_index=k-1;
		for(int i=k; i<n; i++)
		{
			sum=sum+arr[i]-arr[i-k];
			if(sum>max)
			{
			    max=sum;
			    left_index=i-k+1;
			    right_index=i;
			}
		}
		cout<<max<<" from index ("<<left_index<<" - "<<right_index<<")"<<endl;
		
	}
}
