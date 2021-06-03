#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in1.txt");
ofstream outfile("out1.txt");

class graph{
	int v;
	list<int> *adj;
	public:
		graph(int vertex){
			v=vertex;
			adj=new list<int>[v];
		}
		void add_edge(int u,int w){
			adj[u].push_back(w);
			adj[w].push_back(u);
		}
		bool cycle_dfs();
		bool dfs_util(int src,bool visited[],int parent);
		bool cycle_bfs();
};
bool graph::dfs_util(int src,bool visited[],int parent){
	visited[src]=true;
	for(auto & it:adj[src]){
		if(it==parent)
		continue;
		if(visited[it])
		return true;
		 dfs_util(it,visited,src);
		
	}
	return false;
}
bool graph::cycle_dfs(){
	bool visited[v]={false};
	for(int i=0; i<v; i++){
		if(visited[i])
		continue;
		
		bool result=false;
		if(!visited[i])
		result=dfs_util(i,visited,-1);
	
		if(result)
		return true;
    }
    return false;
}
bool graph::cycle_bfs(){
	bool visited[v]={false};
	queue<pair<int,int>> q;
	for(int i=0; i<v; i++){
		if(visited[i])
		continue;
		q.push(make_pair(i,-1));
		visited[i]=true;
		while(!q.empty()){
			int top=(q.front()).first;
			int parent=(q.front()).second;
		
			q.pop();
    		for(auto & it:adj[top]){
    			if(it==parent)
    			continue;
    			if(visited[it])
    			return true;
    			q.push(make_pair(it,top));
    			visited[it]=true;
		    }
		}
	}
	return false;
} 
int main(){
	int t;
	infile>>t;
	while(t--){
		int n,m;
		infile>>n>>m;
		graph gh(n);
		
		for(int i=0; i<m; i++){
			int u,v;
			infile>>u>>v;
			gh.add_edge(u,v);
		}
		
		bool result_dfs=gh.cycle_dfs();
		bool result_bfs=gh.cycle_bfs();
		
		if(result_dfs) outfile<<"dfs cycle present"<<endl;
		else outfile<<"dfs cycle absent"<<endl;
		
		if(result_bfs) outfile<<"bfs cycle present"<<endl;
		else outfile<<"bfs cycle absent"<<endl;
		
		outfile<<endl;

	}
	
}
