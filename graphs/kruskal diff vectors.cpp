#include <bits/stdc++.h>

using namespace std;
 

bool cycle(int edge1,int edge2,vector<int> to ,vector<int> from,int n){
    bool visited[n];
    bool included[n+1];
    for(int i=0; i<n; i++)
    visited[i]=false;
    
    for(int i=0 ; i<from.size(); i++){
    	included[from[i]]=true;
	}
	included[edge1]=true;
    
    list<int> *adj;
    adj = new list<int>[n+1];
    adj[edge1].push_back(edge2);
    for(int i=0; i<from.size(); i++){
        adj[from[i]].push_back(to[i]);
    }
	queue<int> q;
	
	for(int i=1; i<=n; i++){
		if(!included[i])
		continue;
		if(visited[i])
		continue;
		
		q.push(i);
		visited[i]=true;
		
		while(!q.empty()){
			int top=q.front();
			q.pop();
		//	cout<<top<<" : ";
			for(auto &it:adj[top]){
				if(!visited[it]){
					q.push(it);
			//		cout<<it<<" ";
					visited[it]=true;
				}
				else return true;
			}
		//	cout<<endl;
		}
	}
	return false;
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    vector<int> to;
    vector<int> from;
    vector<pair<int,int>> wt_i;
    unordered_map<int,int> sum_i;
    int n= g_nodes;
    int sum=0;
    for(int i=0; i<g_weight.size(); i++){
        wt_i.push_back(make_pair(g_weight[i],i));
    }
    
    sort(wt_i.begin(),wt_i.end());
    for(int i=0; i<g_weight.size(); i++){
        sum_i[i]=(g_from[i]+g_to[i]);
    }
    
    
    int count=0;
   // cout<<n<<endl;
    /*for(int i=0; i<wt_i.size(); i++){
    	cout<<wt_i[i].first<<" "<<wt_i[i].second<<endl;
	}*/
    while(count<n-1){
        int index=0;
        int wt=wt_i[index].first;
      // cout<<wt<<endl;
    // cout<<count<<" ";
        int i=wt_i[index].second;
    //    cout<<i<<endl;
        int min=sum_i[i];
        int j=index;
        while(j<n-1 && wt_i[j].first == wt_i[j+1].first){
        	
            int temp=wt_i[j].second;
    //        cout<<"temp: "<<temp<<" ";
            if(min>sum_i[temp]){
                min=sum_i[j];
                index=j;
            }
            j++;
        }
        i=wt_i[index].second;
    //    cout<<"index : "<<index<<" ";
        wt_i.erase(wt_i.begin()+index);
        
        bool result=cycle(g_from[i],g_to[i],to,from,n);
        if(!result){
        //	cout<<": "<<wt<<endl;
            sum+=wt;
            to.push_back(g_to[i]);
            from.push_back(g_from[i]);
            count++;
        }
    }
    return sum;
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<int> g_from,g_to,g_weight;
    for(int i=0; i<e; i++){
        int value1,value2,weight;
        cin>>value1>>value2>>weight;
        g_from.push_back(value1);
        g_to.push_back(value2);
        g_weight.push_back(weight);
    } 
   // cout<<n<<endl;
    cout<<kruskals(n, g_from, g_to,g_weight);
}
