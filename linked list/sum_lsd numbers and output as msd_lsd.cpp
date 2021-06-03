#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in2.txt");
ofstream outfile("out1.txt");

typedef struct node{
	int data;
	struct node* next;
}node;
void reverse_number(node **number,node *val){
	
}
void insert(node **start,int value){
	node *last,*temp;
	last=*start;
	
	temp=new node();
	temp->data=value;
	temp->next=NULL;
	if( !(*start)){
		(*start) = temp;
	}
	
	else{
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=temp;
		last=temp;
	}
	return;
}

int add(int digit1,int digit2,int *carry){
	
	int value=(*carry)+digit1+digit2;
	if(value>9)
	{
		*carry=1;
		value=value%10;
	}
	else
	*carry=0;
	
//	cout<<value<<" ";
	return value;
}
void append(node **number,int value){
	node *temp;
	temp=new node();
	temp->data=value;
	
	//checked if head/ number == null
	temp->next=(*number);
	
	//append head/number in new node added
	(*number)=temp;
}
void traverse(node *number){
	node *val;
	val=number;
	while(val){
		outfile<<val->data<<" ";
		val=val->next;
	}
	outfile<<endl;
}

node* brute_force(node *number1,node *number2){
	node *number;
	node *val1,*val2;
	val1=number1;
	val2=number2;
	number=NULL;
	
	int carry=0;
	int value=0,digit=0;
	
	while(val1 && val2){
		value=add(val1->data,val2->data,&carry);
		append(&number,value);
		val1=val1->next;
		val2=val2->next;
	}
	while(val1){
		value=add(val1->data,0,&carry);
		append(&number,value);
		val1=val1->next;
	}
	while(val2){
		value=add(val2->data,0,&carry);
		append(&number,value);
		val2=val2->next;
	}
	if(carry!=0){
		append(&number,carry);
		carry=0;
	}
	return number;
}
node *create(int digit_no){
	node *number,*last,*temp;
	int value;
	number=NULL;
	if(digit_no==0)
	{
		infile>>value;
		number = new node();
		number->data=0;
		return number;
	}
	while(digit_no--){
		infile>>value;
		insert(&number,value);
	}
	
	return number;
}
int main(){
	if(!infile){
		cout<<"File is missing"<<endl;
	}
	int t;
	infile>>t;
	while(t--){
		int digit1,digit2;
		infile>>digit1>>digit2;
		
		node *number1,*number2;
		number1=create(digit1);
		number2=create(digit2);
		
		node *result=brute_force(number1,number2);
		traverse(result);
	}
}
