#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long l1;

l1 find_total(int arr[],int n){
	l1 no=pow(2,n);
	l1 total=1;
	l1 count=0;
	for(int i=0; i<n; i++){
		l1 value=1;
		// consider product of all from subarray from arr[i] to arr[n]
		for(int j=i; j<n; j++)
		{
			//value will store also intial result from i to j and update to new result
			value=value*arr[j];
			total=total*value;
		}
	}
	return total;
}
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
		outfile<<find_total(arr,n)<<endl;
	}
}

/* output to be expected
1225
1024000
1048576
0
1
*/
