#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in1.txt");
ofstream outfile("out1.txt");

bool check(int index,int pos,int arr[],int n){
	bool occ[n]={false};
	
	for(int i=0; i<index; i++){
		//cout<<i<<" "<<arr[i]<<endl;
		if(pos == arr[i])
		return false;
	//	cout<<row<<" "<<col<<endl;
	    if((index-i) == (pos-arr[i]) || (index-i)==(arr[i]-pos))
	    return false;
	
	}
	return true;
}

int next_value(int arr[],int index,int n){
	int prev_pos = arr[index];
	int pos=prev_pos+1;
	if(pos==(n+1))
	return 0;
	bool result = check(index,pos,arr,n);

	if(result)
	return pos;
	else{
		// assign curr wrong pos and check for next value
    	arr[index] = pos;
	    return next_value(arr,index,n);
	}
}

bool general(int arr[],int index,int n){
	if(index==n)
	return true;
	int pos=next_value(arr,index,n);
	
	if(index==0 && pos==0)
	return false;
	
	if(pos!=0){
		arr[index] = pos;

        return general(arr,index+1,n);
    }
    arr[index]=0;
    general(arr,index-1,n);
}

void print(int arr[],int n){
	for(int i=0; i<n; i++){
		outfile<<i<<" : "<<arr[i]<<endl;
	}
}

int main(){
	if(!infile){
		cout<<"File missing";
		return 0;
	}
	int t;
	infile>>t;
	while(t--){
	
		int n;
		infile>>n;
		int arr[n];
		for(int i=0; i<n; i++)
		arr[i]=0;
		bool result = general(arr,0,n);
		
		if(result){
    		print(arr,n);
    		outfile<<endl;
    	}
		else
		outfile<<"Not possible"<<endl;
	}
}
