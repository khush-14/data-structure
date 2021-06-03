#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in2.txt");
ofstream outfile("out1.txt");

int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
	
	int n=t_nodes;
	int e=t_edges;
	list<int> adj[n+1];
	int src[n+1];
	unordered_map<int,int> mp;
	for(int i=0; i<t_edges; i++){
		adj[t_to[i]].push_back(t_from[i]);
	}
	bool visited[n+1]={false};
	for(int i=0; i<e; i++){
		visited[t_to[i]]=true;
	}
	
	for(int i=0; i<e; i++){
		src[t_from[i]]=t_to[i];
	}
	
	queue<int> q1;
	bool included[n+1]={false};
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			q1.push(i);
			included[i]=true;
		//	cout<<i<<endl;
		}
	}
	
	for(int i=1; i<=n; i++)
	mp[i]=1;
	while(!q1.empty()){
	
		while(q1.front()==1 && !q1.empty())
		q1.pop();
		
		if(q1.empty())
		break;
		
		int value=q1.front();
		q1.pop();
		int source=src[value];
		mp[source]+=mp[value];
		int flag=0; 
		for(auto & it:adj[source]){
			if(!included[it])
			{
				flag++;
				break;
			}
		}
		if(flag==0){
    		if(!included[source])
	    	q1.push(source);
		    included[source]=true;
		}
	//	cout<<value<<endl;	
	}
//	cout<<"odnr";
	int total=0;
//	cout<<"total"<<endl;
	for(auto it:mp){
		int value=it.first;
		int count=it.second;
//		cout<<value<<" "<<count<<endl;
		
		
		if(count%2==0 && value!=1)
		{
			total++;
		//	cout<<"value: "<<value<<endl;
		}
	}
	return total;
}

int main(){
	if(!infile){
		cout<<"File missing";
		return 0;
	}
	int t;
	infile>>t;
	while(t--){
		int n,e;
		infile>>n>>e;
		vector<int> from;
		vector<int> to;
		for(int i=0; i<e; i++){
			int value1,value2;
			infile>>value1>>value2;
			from.push_back(value1);
			to.push_back(value2);
		}
		cout<<evenForest(n,e,from,to);
	}
}
