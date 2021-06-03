#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in2.txt");
ofstream outfile("out2.txt");

int binarySearch(int arr[],int n,int k){
	int l=0;
	int r=n;
	int mid=0;
	while(l<r)
	{
		mid=(r-l)/2+l;
		if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
		break;
		if(arr[mid]>arr[l])
		{
			l=mid+1;
		}
		else 
		r=mid-1;
	}

    if(arr[mid]==k)
	{
		return mid;
	}
	if(mid<n-1)
	{
		if(arr[0]<=k && arr[mid-1]>=k)
		{	
		    l=0; r=mid;
    	}	
	    else{		
			l=mid+1;
    		r=n-1;
	    }
	}
	while(l<=r)
	{
		mid=(r-l)/2+l;
		if(arr[mid]==k)
		return mid;
		else if(arr[mid]>k)
		r=mid+1;
		else
		l=mid-1;
	}
	return -1;
}
int main(){
	if(!infile)
	{
		cout<<"File Missing";
		return 0;
	}
	int t;
	infile>>t;
	while(t--){
		int n,k;
		infile>>n>>k; 
		int arr[n];
		for(int i=0; i<n; i++)
		infile>>arr[i];
		int result=binarySearch(arr,n,k);
		if(result==-1)
		outfile<<"Not Found"<<endl;
		else
		outfile<<result<<endl;
	}
}
