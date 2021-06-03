#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;
node* create()
{
	int n;
	node *root;
	char choice;
	root=(node*)malloc(sizeof(node));
	printf("enter the data in :");
	scanf("%d",&root->data);
	n=root->data;
	printf("do you want to element in left side of %d(y/n): ",n);
	fflush(stdin);
	scanf("%c",&choice);
	if(choice=='y')
	root->left=create();
	else
    root->left=NULL;
	printf("do you want to enter the element in right side of %d(y/n): ",n);
	fflush(stdin);
	scanf("%c",&choice);
	if(choice=='y')
	root->right=create();
	else 
	root->right=NULL;
	return root;
}
node *insertRecur(node *root,int value)
{
	node *val;
	if(root==NULL)
	{
		val=root;
		val=(node*)malloc(sizeof(node));
		val->data=value;
		val->left=val->right=NULL;
		return val;
    }
	if(value<root->data)
	root->left=insertRecur(root->left,value);
		
	else
	root->right=insertRecur(root->right,value);
		
	
	return root;
	
}

void insertNonRecur(int value,node *root)  
{  
    node *ptr, *parentptr , *nodeptr;  
    ptr = (struct node *) malloc(sizeof (struct node));  
    if(ptr == NULL)  
    {  
        printf("can't insert");  
    }  
    else   
    {  
    ptr -> data = value;  
    ptr -> left = NULL;  
    ptr -> right = NULL;   
    if(root == NULL)  
    {  
        root = ptr;  
        root -> left = NULL;  
        root -> right = NULL;  
    }  
    else   
    {  
        parentptr = NULL;  
        nodeptr = root;   
        while(nodeptr != NULL)  
        {  
            parentptr = nodeptr;   
            if(value < nodeptr->data)  
            {  
                nodeptr = nodeptr -> left;   
            }   
            else   
            {  
                nodeptr = nodeptr -> right;  
            }  
        }  
        if(value < parentptr -> data)  
        {  
            parentptr -> left = ptr;   
        }  
        else   
        {  
            parentptr -> right = ptr;   
        }  
    }  
    printf("Node Inserted");  
    }  
}  
void InorderTraverse(node* root)
{
	node *val,*temp;
	val=root;
	if(val!=NULL)
	{
		InorderTraverse(root->left);
		printf("%d  ",root->data);
		InorderTraverse(root->right);
	}	
}
int main()
{
	int n,value;
	char choice;
	node *root;
	printf("1. create tree \n 2. Inorder traverse \n3.Non recursive Insert \n 4. Recursive Insert \n5. Exit");
	scanf("%d",&n);
	while(n!=5)
	{
		switch(n)
		{
			case 1:{
				root=create();
				break;
			}
			case 2:{
			    InorderTraverse(root);
				break;
			}
			case 4:{
				printf("enter the value:");
				scanf("%d",&value);
				insertRecur(root,value); 
				break;
			}
			case  3:{	
            	printf("enter the data for insertion:");
              	scanf("%d",&value);
               	insertNonRecur(value,root);
				break;
		  	}
		    default:printf("select correct choice:\n");
		}
		printf("\n------------------------------------\n");
		printf("1. create tree \n 2. Inorder traverse \n3.Non recursive Insert \n 4. Recursive Insert \n5. Exit");
	    scanf("%d",&n);
	}
	return 0;
}
//sir search operation is not able to implement
