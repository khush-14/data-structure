#include<iostream>
using namespace std;

typedef struct heap{
	int *array;
	int count;
	int size;
	int heap_type;
};
void insert(heap *h,int data);
struct heap* create(int heap_type,int size){
	struct heap *h;
	h=new heap;
	if(h==NULL){
		cout<<"Memory storage problem";
	    return NULL; 
	}
	h->heap_type=heap_type;
	h->count=0;
	h->size=size;
	h->array=new int[h->size];
	if(h->array==NULL){
		cout<<"Memory Storage problem";
		return NULL;
	}
	return h;
}
int parent(int i,heap *h){
	if(i>=h->count || i<=0)
	return -1;
	return (i-1)/2;
}
int left_child(int i,heap* h){
	if((2*i+1)>=h->count || i<0)
	return -1;
	else
	return 2*i+1;
}
int right_child(int i,heap *h){
	if(2*i+2>=h->count || i<0)
	return -1;
	return 2*i+2;
}

void swap(int *a,int *b){
    int temp=*a;
	*a=*b;
	*b=temp; 	
}

void heapify(heap *h,int i){
	int parent=i;
	int left=2*i+1;
	int right=2*i+2;
	//cout<<h->array[left];
	if(left<=h->count-1)
	{
		if(h->array[left]>h->array[parent])
		parent=left;
	}
	if(right<=h->count-1){
		if(h->array[right]>h->array[parent])
		parent=right;
	}
	if(parent!=i){
		swap(&(h->array[i]),&(h->array[parent]));
		heapify(h,parent);
	}
}

void resize(heap *h){
	heap *temp;
	temp =new heap;
	temp->count=h->count;
	temp->heap_type=h->heap_type;
	temp->size=h->size*2;
	temp->array=new int[2*(h->size)];
	for(int  i=0; i<h->count; i++){
		insert(temp,h->array[i]);
	}
	h=temp;
}
void insert(heap *h,int data){
	if(h->count == h->size )
	resize(h);
	
	int i=h->count;
	h->count=h->count+1;
	while(i>0 && data>h->array[(i-1)/2]){
		h->array[i]=h->array[i/2];
		i=i/2;
	}
	h->array[i]=data;
	cout<<h->array[i]<<" "<<i<<" ";
}
int extract_max(heap *h){
	if(h->count<=0)
	return -1;
	swap(&(h->array[0]),&(h->array[h->count-1]));
	
	int value=h->array[h->count-1];
	h->count=h->count-1;
	heapify(h,0);
	return value;	
}
int max(heap *h){
	if(h->count<=0)
	return -1;
	return h->array[0];
}
void traverse(heap *h){
	if(h->count<=0)
	return;
	else
	for( int i=0; i<h->count; i++){
		cout<<h->array[i]<<endl;
	}
}
int main(){
	struct heap *h;
	int choice;
	cout<<"1.create\t2.Insert\t3.traverse\t4.ExtractMax\t5.Max: ";
	cin>>choice;
	cout<<endl;
	while(choice!=6){
    	switch(choice){
	    	case 1:{
		    	int heap_type;
			    int size;	
            	cout<<"Type of heap is min/max(0/1): ";
            	cin>>heap_type;
            	cout<<"Size of heap: ";
            	cin>>size;
			    h=create(heap_type,size);
    			break;
	    	}
		    case 2:{
			    if(h==NULL)
    			{
	    			cout<<"Heap is not created"<<endl;
		    		break;
			    }
    			int value;
    			cout<<"Enter value to inserted: ";
	    		cin>>value;
		    	insert(h,value);
			    break;
		    }
    		case 3:{
	    		if(h==NULL)
		    	{
			    	cout<<"Heap is not created"<<endl;
				    break;
    			}
    			traverse(h);
	    		break;
		    }
		    case 4:{
		    	cout<<extract_max(h)<<endl;
				break;
			}
			case 5:{
				cout<<max(h);
				break;
			}
			default:{
				cout<<"Select appropriate choice"<<endl;
				break;
			}
	    }
	    cout<<"1.create\t2.Insert\t3.traverse\t4.ExtractMax\t5.Max: ";
	    cin>>choice;
	    cout<<endl;
	}
}
