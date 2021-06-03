// sir my duplicate elements are not considering as different
#include<iostream>
#include<bits/stdc++.h>
#define vec vector<int> // define vector<int> as vec for simplicity
using namespace std;

ifstream infile("in1.txt");
ofstream outfile("out1.txt");


vec partition(vec arr,int val,int order){
	vec x;
	// if order == 0 means low bound  
	if(order==0){
	    for(int i=0; i<arr.size(); i++){
	    	if(arr[i]<val)
	    	x.push_back(arr[i]);
    	}
    }
    // else high bound
    else{
    	for(int i=0; i<arr.size(); i++){
    		if(arr[i]>val)
    		x.push_back(arr[i]);
		}
	}
	return x;
}
int m_o_m(vec arr,int k){
	int n=arr.size();
	int l=0,r;
	r=(n<5)?n:5;
	
	// if k is out of bound
	if(k<=0 || k>n)
	return -1;
	
	vec temp;
	while(l<n){
		sort(arr.begin()+l,arr.begin()+r);
		int mid=(r-l)/2+l;
		
		// push median element in temporary array
		temp.push_back(arr[mid]);
		l=r+1; // increment l = next index of r
	    r = ((r+5)<=n) ? r+5 : n; // r= r+5 if not end elements else n
	}
	
	int i=temp.size();
	int value = i==1?temp[0]:m_o_m(temp,i/2);
	
	int q=0; // elements less than value
	for(int i=0; i<n; i++){
		if(arr[i]<value)
		q++;
	}
	// if q+1 == k then current mid is kth smallest element
	if((q+1)==k)
	return value;
	
	vec x,y;
	x=partition(arr,value,0); // 0 for elements less than value is store in x
	y=partition(arr,value,1);// 1 for elements greater than value is store in x
	
	if(q+1>k)
	return m_o_m(x,k);
	else
	return m_o_m(y,k-(q+1)); // k-q-1 is for q+1 small elements are in arr which are not y
}

vec input(int n){
	vec arr;
	for(int i=0; i<n; i++)
	{
		int j;
		infile>>j;
		arr.push_back(j);
	}
	return arr;
}

int main(){
 	if(!infile){
 		cout<<"File is missing ";
 		return 0;
	}
	int t;
	infile>>t;
	while(t--){
		int n,k;
		infile>>n>>k;
		// vec is define as vector<int> 
		vec arr;
		
		arr=input(n);
		int result=m_o_m(arr,k);
		
		if(result!=-1)
		outfile<<result<<endl;
		else
		outfile<<"Not exist such k in given input"<<endl;
		
	} 
	return 0;
}
