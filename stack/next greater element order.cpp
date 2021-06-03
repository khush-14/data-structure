#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream infile("in1.txt");
	ofstream outfile("out2.txt");
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
		
		//declaration of stack 
		stack<int> s;
		
		//store all arr[i] and ng of arr[i] in map
		//traverse the array 
		unordered_map <int,int> mp;
		
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
		    	//store the arr[i] and NG as key value pair
			    mp[s.top()]=arr[j];
    			s.pop();
	    	}
		    i=j-1;
    	}
	    while(!s.empty()){
	    	//store remaining key elements of array to value as -1 
	    	//whose NG is not present in array
            mp[s.top()]=-1;		    
            s.pop();
    	}
    	for(int i=0; i<n; i++){
    		//traverse the array and find the result
    		outfile<<arr[i]<<"->"<<mp[arr[i]]<<endl;
		}
    	outfile<<endl;
	}
}
