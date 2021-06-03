#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in1.txt");
ofstream outfile("out1.txt");

typedef struct edge{
	int a;
	int b;
	int weight;
};
typedef struct vertices{
	int rank;
	int parent;
};
class dis_set{
	int n, e;
	vector<edge> edges;
	vertices *ver;
	public:
		dis_set(int no){
			n=no;
			create_edges();
			ver= new vertices[no];
			make_set();
		}
		void create_edges(){
			int k=0;
		    int value;
		    edge edg;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					infile>>value;
					if(j<i){
					    continue;
				    }
					
					if(value){
						edg.a=i;
						edg.b=j;
						edg.weight=value;
						k++;
						edges.push_back(edg);
					}
				}
				
			}
			e=k;
		}
		int find_set(int a){
			if(ver[a].parent!=a){
				ver[a].parent=find_set(ver[a].parent);
			}
			return ver[a].parent;
		}
		void union_set(int a,int b){
			int x=find_set(a);
			int y=find_set(b);
			if(ver[x].rank>ver[y].rank){
				ver[y].parent=x;
			}
			else{
				ver[x].parent=y;
				if(ver[x].rank==ver[y].rank)
				ver[y].rank+=1;
			}
		}
		void make_set(){
			for(int i=0; i<n; i++){
				ver[i].parent=i;
				ver[i].rank=0;
			}
		}
		edge ret_edge(int i){
			//cout<<i<<endl;
			edge ed=edges[i];
			return ed;
		}
		int ret_e(){
			return e;
		}
		void heap_sort();
		void percolate_down(int i,int no);
		void swap(int a,int b);
};
void dis_set::swap(int a,int b){
	edge temp;
	temp=edges[a];
	edges[a]=edges[b];
	edges[b]=temp;
}
void dis_set::percolate_down(int i,int no){
	int left=2*i+1;
	int right=2*i+2;
	int largest=i;
	if(left<no && edges[left].weight>edges[largest].weight)
	largest=left;
	
	if(right<no && edges[right].weight>edges[largest].weight)
	largest=right;
	
	if(largest!=i){
		swap(largest,i);
		percolate_down(largest,no);
	}
}
void dis_set::heap_sort(){
	for(int i=e/2; i>=0; i--){
		percolate_down(i,e);
	}
	//cout<<e;
	for(int i=e-1; i>0; i--){
	//	cout<<edges[0].weight<<endl;
		swap(0,i);
		percolate_down(0,i);
	}
}
bool check_cycle(bool *arr[],int n){
	return false;
}
int kruskal_algo(dis_set set,int n){
	list<int> adj[n];
	bool vis[n];
	set.heap_sort();
	int e=set.ret_e();
	
	for(int i=0; i<e; i++)
	cout<<set.ret_edge(i).a<<" "<<set.ret_edge(i).b<<endl;
//	cout<<endl<<endl;

	int count=0,total_weight=0;
	
	for(int i=0; i<e && count<n-1; i++){
		edge ed=set.ret_edge(i);
		
		int a1=ed.a;
		int b1=ed.b;
		int weight=ed.weight;
		vis[a1]=true;
		vis[b1]=true;
		adj[a1].push_back(b1);
		stack<int> s;
		int flag=0;
		cout<<a1<<" "<<b1<<" "<<weight<<endl;
		if(vis[a1] && vis[b1]){
			s.push(a1);
			bool arr[n];
			while(!s.empty()){
				int val=s.top();
				arr[val]=true;
				for(auto& it:adj[val]){
					if(arr[it]){	
				    	flag++;
				    	break;
					}
					if(vis[it]){
						cout<<it<<endl;
			    		s.push(it);
			    		arr[it]=true;
			    	}
				}
				if(flag!=0)
				break;
				if(s.top()==val)
				s.pop();
			}
		}
		if(flag)
		continue;
		cout<<a1<<" "<<b1<<" "<<endl;
		if(set.find_set(a1)!=set.find_set(b1)){
			
			set.union_set(a1,b1);
			
			total_weight+=weight;
		}
		count++;
	}
	return total_weight; 
}

int main(){
	if(!infile){
		cout<<"create the file";
		return 0;
	}
	int t;
	infile>>t;
	while(t--){
		int n;
		infile>>n;
		dis_set set(n);
		outfile<<kruskal_algo(set,n);
		
	}
}

