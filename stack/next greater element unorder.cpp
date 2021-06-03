#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
	ifstream infile("in1.txt");
	ofstream outfile("out1.txt");
	if(!infile)
	cout<<"File is missing";
	int t;
	infile>>t;
	while(t--){
		int n;
		infile>>n;
		int arr[n];
		for(int i=0; i<n; i++)
		infile>>arr[i];
		stack<int> s;
    	for(int i=0; i<n; i++){
	    	s.push(arr[i]);
		    int j=i+1;
    		while(j<n && arr[j]<=arr[j-1])
	    	{
		    	s.push(arr[j]);
			    j++;
    		}
	    	while(!s.empty() && s.top()<arr[j])
		    {
			    outfile<<s.top()<<" -> "<<arr[j]<<endl;
    			s.pop();
	    	}
		    i=j-1;
    	}
	    while(!s.empty()){
		    outfile<<s.top()<<" -> "<<"-1"<<endl;
		    s.pop();
    	}
    	outfile<<endl;
	}
	
}
