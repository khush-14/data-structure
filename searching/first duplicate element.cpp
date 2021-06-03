#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int using_map(int arr[],int n){
	//first int for value second for index
	unordered_map<int,int> mp;
	int min_index=INT_MAX-1;
	for(int i=0; i<n; i++){
		if(mp.find(arr[i])==mp.end())
		mp[arr[i]]=i;
		else{
			int temp=mp[arr[i]];
			if(min_index>temp)
			min_index=temp;
		}
	}
	return arr[min_index];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int element=using_map(arr,n);
		cout<<element<<endl;
	}
}
