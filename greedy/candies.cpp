#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long arrange(int arr[],int n){
	long temp=1;
	int v[n];
	for(int i=0; i<n; i++)
	v[i]=1;
	
	for(int i=1; i<n; i++)
	{
		if(arr[i]>arr[i-1])
		v[i]=v[i-1]+1;
		if(arr[i]<arr[i-1])
		v[i]=min(1,v[i-1]-1);
	}
	for(int i=n-1 ;i>=0; i--){
			if(v[i]<1){
		//	cout<<"IN";
			int k=i;
			temp=v[i-1]-v[i];
			//cout<<"temp: "<<temp<<endl;
			while(k>=1 && temp<=1){
				temp=v[k-1]-v[k];
			//	cout<<temp<<endl;
				v[k]++;
				k--;
			}
			if(temp>1){
				continue;
			}
			if(k==0)
			{
				while(k<i)
				v[k]++;
			}
		}
	}
	long result=0;
	for(int i=0; i<n; i++){
		result+=v[i];
	    cout<<v[i]<<" ";
	}
	
	return result;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	cin>>arr[i];
	long result=arrange(arr,n);
	cout<<result;
}
