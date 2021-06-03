//implementation of priority queue key,value pair by stl;

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

ifstream infile("in1.txt");
ofstream outfile("out1.txt");
	
void change_priority(int value,priority_queue<pair<int,int>>pq){
	cout<<"1";
	if(pq.empty())
	return ;
	
	pi temp;
	priority_queue<pair<int,int>> newpq;
	while(!pq.empty()){
		temp=pq.top();
		if(temp.second==value){
		    int key;
    		infile>>key;
		    newpq.push(make_pair(key,value));
		}
		else
		newpq.push(make_pair(temp.first,temp.second));
		pq.pop();
	}
	
	outfile<<endl;
	pq=newpq;
	return ;
}
void print_pq(priority_queue<pair<int,int>> pq)
{
	priority_queue<pair<int,int>> temp=pq;
	while(!temp.empty()){
		outfile<<temp.top().second<<" ";
		temp.pop();
	}
	outfile<<endl;
	cout<<1;
}
int main(){
	priority_queue<pair<int,int>> pq;
	
	if(!infile){
		cout<<"File missing"<<endl;
		return 0;
	}
	
	int key=0,value,n;
	infile>>n;
	
	for(int i=0; i<n; i++)
	{
		infile>>value>>key;
		pq.push(make_pair(key ,value));
	}
	print_pq(pq);
	int data;
	infile>>data;
	change_priority(data,pq);
	return 0;
}
