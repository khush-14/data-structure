#include<iostream>
#include<bits/stdc++.h>
#define vec vector<pair<int,int>>
using namespace std;

ifstream infile("in2.txt");
ofstream outfile("out1.txt");


/* 
logic is we first include single minimum length of each band by sort wise
include in product sum 
then include remaining sort
*/ 
long greedy_ap(int n,vec v){
	int count_bi=0;
	long prod_sum=0;
	unordered_map<int,bool> check;
	
	vec v1; //smallest element of each band with no. of prev band included (including current also)
	vec v2;
	for(auto it : v){
		int bi=it.second;
		// check if that band is already included or not
		if(check.find(bi)==check.end()){
			count_bi++;
			check[bi]=true;
			
			v1.push_back(make_pair(it.first,count_bi));
		}
		else
		{
			v2.push_back(make_pair(it.first,count_bi));
		}
	}
	for(auto it:v1){
		int temp=it.first*it.second;
		prod_sum+=temp;
	}
	for(auto it:v2){
		int temp=it.first*count_bi;
		prod_sum+=temp;
	}
	return prod_sum;
}

int main(){
    if(!infile){
    	cout<<"File is missing";
    	return 0;
	}	
	int t;
	infile>>t;
	while(t--){
		int n;
		infile>>n;
		vec v;
		
		for(int i=0; i<n; i++){
			int li,bi;
			infile>>li>>bi;
			v.push_back(make_pair(li,bi));
		}
		sort(v.begin(),v.end());
		long result=greedy_ap(n,v);
		outfile<<result<<endl;
	}
}
