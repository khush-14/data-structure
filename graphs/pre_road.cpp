#include<iostream>
#include<bits/stdc++.h>
#define pq priority_queue<pi,vector<pi>,greater<pi>>
using namespace std;

typedef pair<int,int> pi;
class graph{
	int v;
	vector<pi> *adj;
	public:
		graph(int ver){
			v=ver;
			adj=new vector<pi>[v];
		}
		void add_edge(int u,int w,int weight){
			adj[u].push_back(make_pair(w,weight));
			adj[w].push_back(make_pair(u,weight));
		}
		long prims(int src,int bit);
};
pq change_key(pq pq1,int value,int weight){
	pq pq_new;
	while(!pq1.empty()){
		pi top = pq1.top();
		int wei=top.first;
		int key=top.second;
		pq1.pop();
		
		if(key==value){
			pq_new.push(make_pair(weight,value));
		}
		else
		pq_new.push(make_pair(wei,key));
	}
	return pq_new;
}
long graph::prims(int src,int bit){
	bool visited[v]={false};
	unordered_map<int,int> mp;
	unordered_map<int,int> ret_mp;
	pq pq1;
	
	for(int i=0; i<v; i++)
	ret_mp[i]=-1;
	
	
	visited[src]=true;
	for(auto it:adj[src]){
		if(!visited[it.first]){
		    pq1.push(make_pair(it.second,it.first));
	    	mp[it.first]=it.second;
    		ret_mp[it.first]=it.second;
    	}
	}
	while(!pq1.empty()){
		pi top=pq1.top();
		
		int min_weight=top.first;
		int edge=top.second;
		pq1.pop();
		visited[edge]=true;
		
		
		for(auto it:adj[edge]){
			int weight=it.second;
			int temp=weight;
			if(bit)
			weight+=min_weight;
			int value=it.first;
			
			if(visited[value])
			continue;
			
			if(mp.find(value)!=mp.end()){
			    int curr_weight=mp[value];
			    
			    if(curr_weight<=weight)
			    continue;
			    
		     	if(curr_weight>weight){
		        	pq1 = change_key(pq1,value,weight);
		        }
			}
			else{
			    pq1.push(make_pair(weight,value));
        	}
        	
    		mp[value]=weight;
	    	ret_mp[value]=temp;
		}
	}
	long sum=0;
	for(auto it:ret_mp){
		sum+=it.second;
		if(it.second==-1 && it.first!=0)
		return -1;
	}
	return sum;
}

bool check(graph gh,int n,int m){
	long prim=gh.prims(0,0);
	long djkst=gh.prims(0,1);
	if(prim!=djkst || prim==-1)
	return false;
	return true;
}

int main(){
	freopen("in2.txt","r",stdin);
	freopen("out1.txt","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		graph gh(n);
		for(int i=0; i<m; i++){
			int u,v,weight;
			cin>>u>>v>>weight;
			gh.add_edge(u,v,weight);
		}	
		bool result=check(gh,n,m);
		if(result)
		cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
