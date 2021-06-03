#include<iostream>
#define mp unordered_map<int,int>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in1.txt");

void output(vector<pair<int,int>> v,mp m){
	cout<<v.size()<<endl;
	for(auto it:v){
		cout<<it.first<<" "<<it.second<<" "<<m[it.first]<<endl;
	}
	cout<<endl;
}

void print(mp prev,mp m1,mp m2,int n,int p){
	vector<pair<int,int>> v;
	int total=1;
	bool arr[n]={false};
	mp m3;
	
	for(auto it:m1){
		if(arr[it.first])
		{
			continue;
		}
		arr[it.first]=true;
		int value1=it.first;
		int value2=value1;
		int min=m2[value2];
		
		while(prev.find(value1)!=prev.end()){
			arr[value1]=true;
			if(min>m2[prev[value1]])
			min=m2[prev[value1]];
			value1=prev[value1];
		}
		arr[value1]=true;
		while(m1.find(value2)!=m1.end()){
			arr[value2]=true;
			if(min>m2[value2]){
				min=m2[value2];
			}
			value2=m1[value2];
		}
		arr[value2]=true;
		v.push_back(make_pair(value1,value2));
		m3[value1]=min;
		
	}
	output(v,m3);
}
int main(){
	int t;
	infile>>t;
	while(t--){
		int n,p;
		infile>>n>>p;
		mp m1;
	    mp m2;
	    mp prev;
	    for(int i=0; i<p; i++){
	    	int a_i,b_i,d_i;
	    	infile>>a_i>>b_i>>d_i;
	    	m1[a_i]=b_i;
	    	m2[a_i]=d_i;
	    	prev[b_i]=a_i;
		}
		print(prev,m1,m2,n,p);
	}
}
