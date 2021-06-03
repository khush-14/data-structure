#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in2.txt");
ofstream outfile("out1.txt");

class graph{
	int v;
	list<int> *adj;
	public:
		graph(int vertex){
			v=vertex;
			adj=new list<int>[v+1];
			
		}
		void add_edge(int u,int w){
			adj[u].push_back(w);
		}
		void dfs(bool visited[],int src);
		graph transpose();
		void filled(bool visited[],stack<int> *s,int vertex);
		void strongly_component();
};

void graph::dfs(bool visited[],int src){
	outfile<<src<<" ";
	visited[src]=true;
	for(auto &it : adj[src]){
		if(!visited[it])
		dfs(visited,it);
	}
}

graph graph::transpose(){
	graph gt(v);
	for(int i=0; i<v; i++){
		for(auto & it:adj[i]){
			gt.add_edge(it,i);
		}
	}
	
	return gt;
}

void graph::filled(bool visited[],stack<int> *s,int vertex){
	visited[vertex]=true;
	for(auto & it: adj[vertex]){
		if(!visited[it])
		filled(visited,s,it);
	}
	(*s).push(vertex);
}
void graph::strongly_component(){
	stack<int> s;
	graph gt(v);
	bool visited[v]={false};
	for(int i=0; i<v; i++){
		if(!visited[i])
		filled(visited,&s,i);
	}
	
	gt=transpose();
	
	for(int i=0; i<v; i++)
	visited[i]=false;

	while(!s.empty()){
		int value=s.top();
		s.pop();
		if(!visited[value]){
			gt.dfs(visited,value);
			outfile<<endl;
		}
	}
}

int main(){
	if(!infile){
		cout<<"file missing";
		return 0;
	}
	int t;
	infile>>t;
	while(t--){
		int n,e;
		infile>>n>>e;
		
		graph gh(n);
		for(int i=0; i<e; i++){
			int u,v;
			infile>>u>>v;
			gh.add_edge(u,v);
		}
		gh.strongly_component();
		outfile<<endl<<endl;
	}
}
