#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int> g;
	priority_queue<int,vector<int>,greater<int>> gp;
	int n;
	cin>>n;
	while(n!=-1){
		g.push(n);
		gp.push(n);
		cin>>n;
	}
	cout<<endl;
	while(!g.empty()){
		cout<<g.top()<<" ";
		g.pop();
	}
	cout<<endl;
	while(!gp.empty()){
		cout<<gp.top()<<" ";
		gp.pop();
	}
	cout<<endl;
	return 0;
}

