#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void perform_operation(int arr[],int prev_rise[],int n){
	stack<int> s;
	prev_rise[0]=1;
	s.push(arr[0]);
	for(int i=1; i<n; i++){
		if(arr[i]<arr[i-1])
		prev_rise[i]=1;
		else{
			int count=1,j=i-1;
			while(s.size()!=0 && s.top()<=arr[i]){
				count+=prev_rise[j];
				s.pop();
				j--;
			//	cout<<s.size()<<" ";
			}
			prev_rise[i]=count;
		}
		s.push(arr[i]);
	}
}
void printOp(int prev_rise[],int n){
	for(int i=0; i<n; i++)
	cout<<prev_rise[i]<<" ";
	cout<<endl;
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
		int prev_rise[n]={0};
		perform_operation(arr,prev_rise,n);
		printOp(prev_rise,n);
		
	}
}
