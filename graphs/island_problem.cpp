#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in2.txt");
ofstream outfile("out1.txt");
const int MAX=1000;

class graph{
	int v;
	int col;
	vector<vector<bool>> vec;
	public:
		// constructor 
		graph(int vertex,int c,vector<vector<bool>> adj);
		// counting part
		int calculate(bool visited[][MAX],vector<pair<int,int>> list_of_1);
		// check all direction
		bool condition(int i,int j,bool visited[][MAX]);
		// find if adjacent have 1 or not
		vector<pair<int,int>> find(queue<pair<int,int>> q,bool visited[][MAX]);
};
graph::graph(int vertex,int c,vector<vector<bool>> adj){
	this->v=vertex;
	this->col=c;
	for(int i=0; i<v; i++){
		vec.push_back(adj[i]);
	}
}
bool graph::condition(int i,int j,bool visited[][MAX]){
	// check if at location i, j '1' or not
	if(vec[i][j]){
		if(!visited[i][j]){
			visited[i][j]=true;
			return true;
		}
	}
	return false;
}

// check in all diagonal sides
vector<pair<int,int>> graph::find(queue<pair<int,int>> q,bool visited[][MAX]){
	// access front element
	pair<int,int> pi=q.front();
	int i=pi.first;
	int j=pi.second;
	
	// for storing all adjacent vertices having 1
	vector<pair<int,int>> ret_vec;
	if(i>0){
		if(condition(i-1,j,visited))
		ret_vec.push_back(make_pair(i-1,j));
		
		if(j>0)
	    	if(condition(i-1,j-1,visited))
		    ret_vec.push_back(make_pair(i-1,j-1));
		if(j<col-1)
	    	if(condition(i-1,j+1,visited))
		    ret_vec.push_back(make_pair(i-1,j+1));
		
	}
	
	if(i<v-1){
		if(j>0)
    		if(condition(i+1,j-1,visited))
	    	ret_vec.push_back(make_pair(i+1,j-1));
		
		if(condition(i+1,j,visited))
		ret_vec.push_back(make_pair(i+1,j));
		
		if(j<col-1)
		    if(condition(i+1,j+1,visited))
		    ret_vec.push_back(make_pair(i+1,j+1));
	}
	
	if(j>0){
		if(condition(i,j-1,visited))
		ret_vec.push_back(make_pair(i,j-1));
	}
	if(j<col-1){
		if(condition(i,j+1,visited))
		ret_vec.push_back(make_pair(i,j+1));
	}
	return ret_vec;
}
int graph::calculate(bool visited[][MAX],vector<pair<int,int>> list_of_1){
	
	int count_1=1;
	int n=list_of_1.size();
	int temp=0;
	queue<pair<int,int>> q;
	int total=0;
	int i=0,j=0;
	while(count_1!=n && temp<n){
	
	    i=list_of_1[temp].first;
		j=list_of_1[temp].second;
		while(visited[i][j] && temp<n-1){
			temp++;
	        i=list_of_1[temp].first;
		    j=list_of_1[temp].second; 
		}
		if(temp>=n-1 && visited[i][j])
		break;
		
		q.push(make_pair(i,j));
		visited[i][j]=true;
		
		while(!q.empty() ){
			
			vector<pair<int,int>> check= find(q,visited);
			q.pop();
			count_1+=check.size();
			for(auto it:check){
				q.push(make_pair(it.first,it.second));
			}
		}
		temp++;
		total++;
	}
	return total;
}
int initialize(vector<vector<bool>> adj,int n1,int n2,graph gh){
	vector<pair<int,int>> list_of_1;
	bool visited[n1][MAX];
	
	// list_of_1 to store all index of 1 // created successfully
	for(int i=0; i<n1; i++){
		for(int j=0; j<n2; j++){
			visited[i][j]=false;
			if(adj[i][j]){
				list_of_1.push_back(make_pair(i,j));
			}
		}
    }
	int total=gh.calculate(visited,list_of_1);
	return total;
}
int main(){
	if(!infile){
		cout<<"file missing";
		return 0;
	}
	int t;
	infile>>t;
	while(t--){
		int n1,n2;
		infile>>n1>>n2;
		
		vector<vector<bool>> v1;
		for(int i=0; i<n1; i++){
			vector<bool> v;
			for(int j=0; j<n2; j++){
				int value;
				infile>>value;
				v.push_back(value);
			}
			v1.push_back(v);
		}
		graph gh(n1,n2,v1);
	    outfile<<initialize(v1,n1,n2,gh)<<endl;
	}
}
