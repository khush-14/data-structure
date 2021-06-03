#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{
	long v;
	list<long> *adj;
	public:
		graph(long vertices){
			v=vertices;
			adj=new list<long>[v+1];
			
		}
		void add_edge(long u,long w){
			adj[u].push_back(w);
			adj[w].push_back(u);
		}
		long calculate(long cb,long cr);
	
};
bool check(bool visited[],long v){
	for(long i=0; i<=v; i++){
		if(!visited[i])
		return false;
	}
	return true;
}
long graph::calculate(long cb,long cr){
	bool visited[v+1]={false};
	long node=0;
	stack<long> s;
	long count_cr=0;
	if(cb<cr)
	return v*cb;
	
	long i=1;
	while(!check(visited,v)){
		while(i<=v && visited[i])
		i++;
		if(i==v+1)
		break;
		//cout<<i<<" ";
		s.push(i);
		visited[i]=true;
		while(!s.empty()){
			int value=s.top();
		//	cout<<value<<" ";
			for(auto & it:adj[value]){
				if(!visited[it]){
					count_cr++;
					visited[it]=true;
					s.push(it);
				}
			}
			if(value==s.top())
			s.pop();
		}
		node++;
	}
//	cout<<":"<<count_cr;
	return node*cb+count_cr*cr;
}

int main(){
    long t;
	cin>>t;
	while(t--){
		long n,m,cb,cr;
		cin>>n>>m>>cb>>cr;
		graph gh(n);
	//	cout<<":"<<m<<endl;
		for(long i=0; i<m; i++){
			
			long u,v;
			cin>>u>>v;
    		gh.add_edge(u,v);
    	}
    	cout<<gh.calculate(cb,cr)<<endl;
	}	
}
