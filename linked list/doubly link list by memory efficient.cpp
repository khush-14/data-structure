#include<iostream>
using namespace std;
typedef struct node{
	int data;
	struct node* link;
}node;
node *create(){
	node *head,*temp,*last,*prev;
	head = new node();

	int value = 0;
	cout<<"enter the value: ";cin>>value;
	head->data=value;
	prev=NULL;
	last=head;
	
	cin>>value;
	while(value!=-1);
	{
		temp = new node();
		temp->data=value;
		last->link=reinterpret_cast<node *>(
		reinterpret_cast<uintptr_t>(prev)^
		reinterpret_cast<uintptr_t>(temp)
		);
		prev=last;
		last=temp;
		cin>>value;
	}
	last->link=prev;
	cout<<
	return head;
}
node *insert(){
}
void traverse(node *head){
	node *val,*next,*temp;
	val=head;
	if(head==NULL)
	return ;
	node *prev;
	prev=NULL;
	next=val->link;
	while(val!=NULL){
		cout<<val->data<<" ";
		temp=val;
		val=reinterpret_cast<node *>(
		reinterpret_cast<uintptr_t>(prev)^
		reinterpret_cast<uintptr_t>(val->link));
		prev=temp;
	}
	cout<<endl;
}
int main(){
	node *head;
	head=create();
	cout<<endl;
	traverse(head);
}
