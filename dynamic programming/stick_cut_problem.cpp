#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
	    sort(arr,arr+n);
    	int temp[n]={0};
	    temp[0]++;
     	int count=0;
	    for(int i=1; i<n; i++){
		    if(arr[i]==arr[i-1])
    		temp[count]++;
	    	else{
		    	count++;
			    temp[count]++;
		    }
	    }
	    int total=n;
    	for(int i=0; i<=count; i++){
    		total=total-temp[i];
	    	cout<<total<<" ";
	    }
	    cout<<endl;
	}
}
