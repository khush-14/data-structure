#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in1.txt");
ofstream outfile("out1.txt");

// node for hoffman graph 
typedef struct node{
	int frequency;
	string s;
	struct node *left;
	struct node *right;
	vector<char> code;
}node; 

//swap function
void swap(node** a,node **b){
	node *temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

//heapify function
void hashing(node* ptr[],int i,int n){
	int parent=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n){
		if((ptr[left]->frequency)<(ptr[parent]->frequency))
		parent = left;
	}
	if(right<n){
		if((ptr[right]->frequency)<(ptr[parent]->frequency))
		parent = right;
	}
	if(parent!=i){
		swap(&ptr[i],&ptr[parent]);
		hashing(ptr,parent,n);
	}
}

//create heap
void hashin(node *ptr[],int n){
	for(int i=n/2; i>=0; i--){
		hashing(ptr,i,n);
	}
}

//extract minimum 
node* extract_min(node *ptr[],int n){
	if(ptr==NULL)
	return NULL;
	node *temp=ptr[0];
	swap(&ptr[0],&ptr[n-1]);
	
	hashing(ptr,0,n-1);
	
	return temp;
}

// create hoffman graph
node* hoffman_cod(node *ptr[],int n){
	
	hashin(ptr,n);
	int temp=n;
	while(temp!=1){
		node *p1,*p2;
		p1=extract_min(ptr,temp);
		temp--;
		
		p2=extract_min(ptr,temp);
		temp--;
		
		node *huff;
		huff = new node();
		huff->frequency=p1->frequency+p2->frequency;
		huff->left=p1;
		huff->right=p2;
		
		ptr[temp]=huff;
		temp++;
		if(temp!=1){
	    	swap(&ptr[temp-1],&ptr[0]);
	    	hashin(ptr,temp);
	    }
	   
	}
	// return root node 
	return ptr[temp-1];
}

//code creation
void preorder(node *ptr,vector<char> n){
	if(ptr->left==NULL){
		ptr->code=n;
		return ;
	}
	vector<char> ch_l;
	vector<char> ch_r;
	ch_l=n;
	ch_l.push_back('0');
	ch_r=n;
	ch_r.push_back('1');
	preorder(ptr->left,ch_l);
	preorder(ptr->right,ch_r);
}

// print code with respective of their string
void print(node* ptr){
	if(ptr->left==NULL || ptr->right==NULL)
	{
		outfile<<ptr->s<<"\t\t";
		for(int i=0; i<(ptr->code).size(); i++){
			outfile<<(ptr->code)[i];
		}
		outfile<<endl;
		return ;
	}
	print(ptr->left);
	print(ptr->right);
}

int main(){
	if(!infile){
		cout<<"FILE IS MISSING "<<endl;
		return 0;
	}
	int t;
	infile>>t;
	while(t--){
		int n;
		infile>>n;
		node *ptr[n];
		// input through array of pointer
		for(int i=0; i<n; i++){
			ptr[i] = new node();
			infile>>ptr[i]->s>>ptr[i]->frequency;
		}
		// create hoffman graph
		node *result = hoffman_cod(ptr,n); // result will store root node
		
		vector<char> code;
		// code creation
		preorder(result,code);
		
		// codes are created for printed
		outfile<<"String"<<"\t\t"<<"Code"<<endl;
		print(result);
		outfile<<endl;
		
	}
	return 0;
}

