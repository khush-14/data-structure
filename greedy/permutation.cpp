#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void compute(int arr[],int n,int k){
	unordered_map<int,int> mp;
	int max=n;
	int pos=0;
	for(int i=0; i<n; i++){
		mp[arr[i]]=i;
	}
	int temp=k;
	while(temp!=0 && pos<n){
		int index=mp[max];
		if(index==pos)
		max--;
		else{
			swap(&arr[pos],&arr[index]);
			temp--;
			max--;
		}
		pos++;
	}
	for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
	return ;
}

int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	compute(arr,n,k);
	return 0;
}
