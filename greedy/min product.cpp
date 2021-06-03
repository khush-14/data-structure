#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in1.txt");
ofstream outfile("out1.txt");
 
long minimum(int n,int arr[]){
	long min=99999;
	for(int i=0; i<n; i++)
    	if(arr[i]<min) 
	        min=arr[i];
	
	return min;
}


long greedy_app(int n,int arr[]){
	int count_neg=0;
	int flag=0;
	int i=0;
	
	for(int i=0; i<n; i++){
		if(arr[i]<0)
		count_neg++;
	}
	if(count_neg!=0){
		flag++;
	}
	long product=1;
	long mini=minimum(n,arr);
	if(flag){
		
		for(int i=0; i<n; i++){
			if(arr[i]==0)
			    continue;
			if(arr[i]==mini && count_neg%2==0)
		    	continue;
			product=product*arr[i];
		}
		return product;
	}
	else{
		return mini;
	}
}

int main(){
    if(!infile){
    	cout<<"File is Missing";
    	return 0;
	}	
	int t;
	infile>>t;
	while(t--){
		int n;
		infile>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			infile>>arr[i];
		}
		long result=greedy_app(n,arr);
		outfile<<result<<endl;
	}
}
