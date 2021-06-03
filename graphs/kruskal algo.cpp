#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in1.txt");
ofstream outfile("out1.txt");

class dis_set{
	int *rank,*parent,*weight,*src,n;
	public:
		dis_set(int no);
		void union_set(int x,int y,int value);
		int find(int x);
		void make_set();
		void kruskal_algo();
		int get_wt(int x);
		int get_src(int x);
		void print();
};
int dis_set::get_src(int x){
	return src[x];
}
int dis_set::get_wt(int x){
	return weight[x];
}
dis_set::dis_set(int no){
	n=no;
	rank = new int[n];
	parent= new int[n];
	weight=new int[n];
	src=new int[n];
	make_set();
}
void dis_set::make_set(){
	for(int i=0; i<n; i++){
		parent[i]=i;
		weight[i]=INT_MAX;
	}
}
int dis_set::find(int x){
	if(parent[x]!=x){
		parent[x]=find(parent[x]);
	}
	return parent[x];
}
void dis_set::union_set(int x,int y,int value){
	int x_set=find(x);
	int y_set=find(y);
	
	// if both belongs to same set
//	cout<<x<<" "<<y<<endl;
	if(x_set==y_set){
		if(weight[y]<=value)
		return ;
		weight[y]=value;
		//cout<<y<<" "<<x;
	}
	
	if(rank[x_set]<rank[y_set]){
		parent[x_set]=y_set;
		weight[x]=value;
	}
	else if(rank[y_set]<rank[x_set]){
		parent[y_set]=x_set;
		weight[y]=value;
	
	}
	else{
		parent[y_set]=x_set;
		weight[y]=value;
		
		rank[x_set]++;
	}
		if(src[x]!=y)
		src[y]=x;
//	cout<<y<<" "<<src[y]<<endl;
}
void dis_set::print(){
	for(int i=0; i<n; i++){
		cout<<i<<" "<<src[i]<<endl;
	}
}
dis_set create_set(int n){
	dis_set obj(n);
	//cout<<n<<endl;
	vector<vector<int>> matrix;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int value;
			infile>>value;
			if(value){
			//	cout<<i<<" "<<j<<" ";
				obj.union_set(i,j,value);
			}
			
		}
	//	cout<<endl;
	}
	obj.print();
	return obj;
}

void kruskal_algo(dis_set obj,int n){
	vector<pair<int,int>> pi;
	for(int i=0; i<n; i++){
		if(obj.find(i)!=i){
			pi.push_back(make_pair(obj.get_wt(i),i));
		}
	}
	sort(pi.begin(),pi.end());
	bool visited[n]={false};
	for(auto it:pi){
		int dest=it.second;
		int src=obj.get_src(src);
		int weight=it.first;
		
		outfile<<src<<" "<<dest<<" "<<weight<<endl;
		visited[src]=true;
		visited[dest]=true;
		
	}
}

int main(){
    if(!infile){
    	cout<<"Create the file";
    	return 0;
	}
	int t;
	infile>>t;
	while(t--){
		int n;
		infile>>n;
		dis_set obj(n);
		obj = create_set(n);
		kruskal_algo(obj,n);
	}
}
