#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* link;
}node;
node* reverse(node *start);
node* create();
void traverse(node *start);

node *create()
{
	node *start,*last,*temp;
	printf("enter the elements while enter the -1: \n");
	start=(node*)malloc(sizeof(node));
	scanf("%d",&start->data);
	last=start;
	int i,choice;
	scanf("%d",&i);
	while(i!=-1)
	{
		temp=(node*)malloc(sizeof(node));
		temp->data=i;
		last->link=temp;
		last=temp;
		scanf("%d",&i);
	}
	last=NULL;
	printf("\n2.reverse\t1.traverse\t3.exit \n");
	scanf("%d",&choice);
	while(choice!=3)
	{
	    
	    switch(choice)
	    {
	    	case 1:
	    	{
	    		traverse(start);
	    		break;
			}
			case 2:
			{
				reverse(start);
				break;
			}
		}
		printf("\n1.reverse\t2.traverse\t3.exit \n");
	    scanf("%d",&choice);
	}
	return start;
}

void traverse(node* start)
{
	node *val;
	val=start;
	while(val!=NULL)
	{
		printf("\n");
		printf("%d",(val->data));
		val=val->link;
	}
	printf("\n");
}
node* reverse(node *start)
{
	node *pn,*nn,*cn;
	pn=start;
	cn=start->link;
	nn=start->link;
	cn->link=pn;
	while(start!=NULL)
	{
		start=start->link;
		cn->link=pn;
		pn=cn;
		cn=start;
	}
	start=pn;
	return start;
}
int main()
{
	create();
}
