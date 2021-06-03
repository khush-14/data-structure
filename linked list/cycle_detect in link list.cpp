#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//   I/O file
ifstream infile("in1.txt");
ofstream outfile("out1.txt");

typedef struct node{
	int data;
	struct node* link;
}node;


void insert(node **start,int value){
	node *temp,*last;
	temp = new node();
	node *val;
	val=(*start);
	while((val->link)!=NULL){
		val=val->link;
	}
	last=val;
	temp->data=value;
	last->link=temp;
	last=temp;
	
}
//creation of link list
node *create(int start_cycle,int end_cycle){
	node *start,*temp,*last,*prev;
	int value;
	infile>>value;
	if(value==-1)
	return start;
	
	start = new node();
	
	start->data=value;
	last=start;
	prev=NULL;
	end_cycle--,start_cycle--; // decrement due to 1 node is already inserted in linklist
	if(start_cycle==0)
	prev=last;
	while(end_cycle--){
		infile>>value;
		//insert new node
		insert(&start,value);
		
		start_cycle--;
		// if starting point of cycle is reached then store in variable else loop goes
		if(start_cycle==0){
			prev=last; 
		}
	}
	
	//assign end link of cycle with start point stored in variable
	last->link=prev;
	if(prev)
	return start;
}
bool brute_force(node *start){
	//declaration of dynamic storage to allocate in node and then check by using loop
	vector<node*> vec; 
	
	node *val;
	int flag=0; // if repeated node will come then increment 
	val=start;
	while(val!=NULL){
		//check if node is already there in vector or not
		for(int i=0; i<vec.size(); i++){
			if(vec[i]==val){
				flag++;
				break;
			}
		}
		if(flag==1)
		break;
		//else push in vector
		vec.push_back(val);
		val=val->link;
	}
	if(flag==0)
	return false;
	return true;
}
bool hashing(node *start){
	node *val;
	unordered_map<node *,bool> cycle;
	val=start;
	int flag=0; // if repeated node will come then increment 
	while(val!=NULL){
		//check in map that current node is already there or not in map
		if(cycle.find(val)!=cycle.end()){
			flag++;
			break;
		}
		//else push node in map
		cycle[val]=true;
		val=val->link;
	}
	if(flag==0)
	return false;
	return true;
}
int main(){
	if(!infile){
		cout<<"File is missing"<<endl;
		return 0;
	}
	int t;
	
	infile>>t;
	while(t--){
		int start_point,end_point;
		// value after which cycle is there -1 if not cycle
		infile>>start_point>>end_point;
		
    	node *start;
	    start=create(start_point,end_point);
    	
		bool result = hashing(start);
    //    bool result = brute_force(start);
	    
		if(result==true)
    	outfile<<"True"<<endl;
	    else
    	outfile<<"False"<<endl;
    	delete start;
    }
}
