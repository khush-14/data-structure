#include<iostream>
#include<bits/stdc++.h>
#define pq priority_queue<pi,vector<pi>,greater<pi>> 
using namespace std;
typedef pair<int,int> pi;

ifstream infile("in2.txt");
ofstream outfile("out1.txt");

class graph{
	int v;
	vector<pair<int,int>> *adj;
	public:
		graph(int vertices){
			v=vertices;
			adj = new vector<pi>[v];
		}
		void add_edge(int src,int dest,int weight){
			adj[src].push_back(make_pair(dest,weight));
			adj[dest].push_back(make_pair(src,weight));
		}
		void djkstra(int src);
};
pq decrease_key(pq pq1,int value,int weight){
	priority_queue<pi,vector<pi>,greater<pi>> newpq;
	while(!pq1.empty()){
		pi top =pq1.top();
		int wei=top.first;
		int val=top.second;
		if(value==val){
			wei=weight;
		}
		newpq.push(make_pair(wei,val));
		pq1.pop();
	}
	return newpq;
}
void graph::djkstra(int src){
	bool visited[v]={false};
	pq pq1;
	int value=src;
	unordered_map<int,int> mp;
	for(auto it:adj[value]){
		if(!visited[it.first]){
			pq1.push(make_pair(it.second,it.first));
			mp[it.first]=it.second;
    	}
	}
	outfile<<value<<" ";
	visited[value]=true;
	while(!pq1.empty()){
		
		pi top=pq1.top();
		
		int value=top.second;
		int weight=top.first;
		outfile<<value<<" ";
		visited[value]=true;
		pq1.pop();
		
		for(auto it:adj[value]){
			int new_weight=it.second+weight;
			int adj_value=it.first;
			if(visited[adj_value])
			continue;
			if(mp.find(adj_value)==mp.end()){
				pq1.push(make_pair(new_weight,adj_value));
				mp[adj_value]=new_weight;
			}
			else{
				int prev_wei=mp[adj_value];
				if(prev_wei>new_weight){
					pq1=decrease_key(pq1,adj_value,new_weight);	
				}
			}
		}
	}
}
int main(){
	if(!infile){
		cout<<"File is missing"<<endl;
		return 0;
	}
	int t;
	infile>>t;
	while(t--){
    	int vertices;
		infile>>vertices;
		graph gh(vertices);
		int no_of_edges;
		infile>>no_of_edges;
		for(int i=0; i<no_of_edges; i++){
			int src,dest,weight;
			infile>>src>>dest>>weight;
			gh.add_edge(src,dest,weight);
		}
		int src;
		infile>>src;
		gh.djkstra(src);		
	}
}
