#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in1.txt");
ofstream outfile("out1.txt");

typedef struct node{
	int data;
	struct node* next;
}node;
void insert(node **start,int value){
    node *last,*val,*temp;
	val=*(start);
	while((val->next)!=NULL){
		val=val->next;
    }
    temp = new node();
    temp->data=value;
    val->next=temp;
    val=temp;
}
void conversion(node **start){      //  O(n)
	node *val;
	val=*(start);
	node *odd_ptr,*even_ptr;
	odd_ptr=*(start);
	even_ptr=*(start);
	//manage the position of odd and even elements 
	int odd_count=0,even_count=0;
	while(odd_ptr!=NULL){
		if((odd_ptr->data)%2)
		break;
		odd_ptr=odd_ptr->next;
		odd_count++;
	}
	
	if(!odd_ptr)
	return ;
	while(even_ptr && odd_ptr){
		if((even_ptr->data)%2 || even_count<=odd_count){
			even_ptr=even_ptr->next;
			even_count++;
			continue;
		}
		
		val=new node();
		val->data=even_ptr->data;
		even_ptr->data=odd_ptr->data;
		odd_ptr->data=val->data;
		
		while(odd_ptr){
			if((odd_ptr->data)%2)
			break;
			odd_ptr=odd_ptr->next;
		}
	}
	return;
}
node *create(){
	node *start,*last;
	int value;
	infile>>value;
	if(value==-1)
	return start;
	
	start = new node();
	start->data = value;
	last=start;
	
	infile>>value;
	while(value!=-1){
		insert(&start,value);
		infile>>value;
	}
	return start;
	
}
void traverse(node *start){
	node *val=start;
	while(val)
	{
		outfile<<val->data<<" ";
		val=val->next;
	}
	outfile<<endl;
}
int main(){
    if(!infile){
    	cout<<"File is missing"<<endl;
    	return 0;
	}	
	int t;
	infile>>t;
	while(t--){
		node *start;
		start=create();
	//	traverse(start);
		conversion(&start);
		traverse(start);
	}
}
