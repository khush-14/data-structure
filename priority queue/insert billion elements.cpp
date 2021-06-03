/*
gquiz.push(1); O(logn) time
gquiz.pop();   O(logn) time
gquiz.top();   O(1)    time
gquiz.size();  O(1)    time
mypqueue1.swap(mypqueue2);
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in1.txt");
ofstream outfile("out1.txt");

void insert(priority_queue<int> pq){
	int k;
	infile>>k;
	if(k==0)
	return;
	priority_queue<int> temp;
	for(int i=0; i<10; i++)
	{
		temp.push(pq.top());
		pq.pop();
	}
	pq=temp;
	for(int i=0; i<40; i++)
	{
		int j;
		infile>>j;
		pq.push(j);
	}
}
int main(){
	if(!infile)	
	{
		cout<<"File Missing";
		return 0;
	}
	priority_queue<int> pq;
	for(int i=0; i<50; i++)
	{
		int j;
		infile>>j,pq.push(j);
	}
	insert(pq);
	
}
