#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}node;
void traverse(node *start3);
node *start,*start2;
node* create1()
{
	node *temp,*last;
	int i;
	start=(node*)malloc(sizeof(node));
	printf("enter the elementsiin list x till -1 enter : \n");
	scanf("%d",&start->data);
	last=start;
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
	return start;
}
node *create2()
{
	node *temp,*last;
	int i;
	start2=(node*)malloc(sizeof(node));
	printf("enter the elements in list y till -1 enter : \n");
	scanf("%d",&start2->data);
	last=start2;
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
	return start2;
}
node* merging()
{
	node *start3,*temp,*last,*val1,*val2,*p;
	start3=(node*)malloc(sizeof(node));
	val1=start;
	val2=start2;
	if(val1->data<val2->data)
	{
		start3->data=val1->data;
		p=val1;
		val1=val1->link;
	}
	else
	{
		start3->data=val2->data;
		p=val2;
		val2=val2->link;
	}
	free(p);
	last=start3;
	while(val1!=NULL && val2!=NULL)
	{
		temp=(node*)malloc(sizeof(node));
		if(val1->data<val2->data)
		{
			temp->data=val1->data;
			p=val1;
			val1=val1->link;
		}
		else
		{
			temp->data=val2->data;
			p=val2;
			val2=val2->link;
		}
		last->link=temp;
		last=temp;
		free(p);
	}
	while(val1!=NULL)
	{
		temp=(node*)malloc(sizeof(node));
		temp->data=val1->data;
		p=val1;
		val1=val1->link;
		last->link=temp;
		last=temp;
		free(p);
	}
	while(val2!=NULL)
	{
		temp=(node*)malloc(sizeof(node));
		temp->data=val2->data;
		p=val2;
		val2=val2->link;
		last->link=temp;
		last=temp;
		free(p);
	}
	last=NULL;
	traverse(start3);
	return start3;
}
void traverse(node *start3)
{
	node *val;
	val=start3;
	while(val!=NULL)
	{
		printf("\n %d",val->data);
		val=val->link;
	}
}
int main()
{
	create1();
	create2();
	merging();
}
