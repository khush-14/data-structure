#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in2.txt");
ofstream outfile("out1.txt");

class graph{
	int v;
	list<int>* adj;
	void dfs(bool arr[],int src);
	public : 
	    graph(int vertices);
    	void addEdge(int u,int w);
	    void DFS_util(int src);
	    void BFS(int src);
};
graph::graph(int vertices){
	v=vertices;
	adj=new list<int>[v+1];
}
void graph::addEdge(int u,int w){
	adj[u].push_back(w);
	adj[w].push_back(u);
}
void graph::dfs(bool arr[],int src){
	arr[src]=true;
	outfile<<src<<" ";
	cout<<src<<" ";
	list<int>::iterator it;
	for(it=adj[src].begin(); it!=adj[src].end(); it++){
		cout<<*it<<" ";
		if(!arr[*it])
    		dfs(arr,*it);
	}
}
void graph::DFS_util(int src){
	bool arr[v+1];
	for(int i=0; i<v; i++){
		arr[i]=false;
	}
	dfs(arr,src);
}
void graph::BFS(int src){
	queue<int> q;
	bool arr[v+1]={false};
	q.push(src);
	q.push(-5);
	int level=1;
	unordered_map<int,int> mp;
	while(!q.empty()){
		int front=q.front();
		q.pop();
		if(front==-5){
			front=q.front();
			level++;
			q.pop();
			q.push(-5);	
		}
		if(!arr[front]){
			arr[front]=true;
		}
		for(auto & it:adj[front]){
			if(!arr[it]){
				arr[it]=true;
				mp[it]=level;
				q.push(it);
			}
		}
	}
	for(int i=1; i<=v; i++){
		if(src==i)
		continue;
		if(arr[i])
		cout<<mp[i]*6<<" ";
		else
		cout<<-1<<" ";	
    }
    cout<<endl;
}
int main(){
	if(!infile){
		cout<<"file missing";
		return 0;
	}
	int t;
	infile>>t;
	while(t--){
		int v;
		infile>>v;
		graph gh(v);
		int no_edge;
		infile>>no_edge;
		for(int i=0; i<no_edge; i++){
			int u,w;
			infile>>u>>w;
			gh.addEdge(u,w);
		}
		int src;
		infile>>src;
	//	gh.DFS_util(src);
	//	outfile<<endl;
	//	outfile<<"BFS: ";
		gh.BFS(src);
		outfile<<endl;
	}
}
