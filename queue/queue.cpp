#include<stdio.h>
#define MAX 5
void enqueue();
void dequeue();
void display();

int queue[MAX];
int front=-1,rear=-1;
int main()
{
	int ch;
	do
	{
		printf("\n 1. insert \n 2. deletion \n 3. display \n exit");
		printf("\n enter the choice");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:  enqueue();
			break;
			case 2: dequeue();
			break;
			case 3: display();
			break;
		}
	}while(ch!=4);
}
void enqueue()
{
	int item,i;
	if(front==0 && rear==MAX-1)
	{
		printf("\n queue over flow");
		
	}
	else
	{
		printf("\n enter element which you want to insert");
		scanf("%d",&item);
		
		if(front==-1)
		{
			front=rear=0;
		}
		else if(rear==MAX-1)
		{
			for(i=front; i<=rear; i++)
			{
				queue[i-front]=queue[i];
			}
			rear=rear-front+1;
			front=0;
		}
		else
		{
			rear++;
		}
		queue[rear]=item;
	}
}
void dequeue()
{
	if(front==-1)
	{
		printf("\n queue underflow \n");
	}
	else{
		printf("\n %d DELETED FROM queue \n",queue[front]);
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front++;
		}
	}
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("\n queue underflow");
	}
	else
	{
		printf("\n queue elements ---> \n");
		
		for(i=front; i<=rear; i++)
		{
			printf("%d",queue[i]);
		}
	}
}

