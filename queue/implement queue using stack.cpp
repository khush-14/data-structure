#include<iostream>
#include<bits/stdc++.h>
using namespace std;
static int Max=1000;
class queu
{
	stack<int> s1,s2;
	int top1,top2;
	public:
		queu();
		void push();
	    int pop();
}obj;
queu::queu(){
	top1=-1;
	top2=-1;
}
void queu::push(){
		    if(top1==Max)
		    cout<<"Queue if full";
		    else
		    {
		    	top1++;
		    	int value;
		    	cin>>value;
		    	s1.push(value);
		    }
	    }
int queu::pop(){
		    if(s1.empty() && s2.empty()){
		    	cout<<"QUEUE is Empty";
			}	
			else{
				if(s2.size()==0){
					while(!s1.empty()){
						int value=s1.top();
						s2.push(value);
						s1.pop();
					}
				}
				int temp=s2.top();
				s2.pop();
				cout<<"Removed Element is : "<<temp<<endl;
			}
		}
class SingleStack{
	stack<int> s;
	public:
		int rec_queue(){
	    	int value,temp;

	        if(s.empty())
        	{
	    	    cout<<"Stack is Empty";
	        	return -1;
    	    }
    	    else if(s.size()==1)
	        {
	        	value=s.top();
    		    s.pop();
    		    return value;
	        }
    	    else{
		        temp=s.top();
    	    	s.pop();
        		value=rec_queue();
		        s.push(temp);
	    	    return value;
    	    }
        }
        void push(){
        	int value;
        	cin>>value;
        	s.push(value);
		}

};
int perform_choice(){
	int choice;
	cout<<"1.Insert\t2.remove\t3.exit"<<endl;
	cin>>choice;
	return choice;
}
void perform_operation1(int choice){
	switch(choice){
    	case 1:{
    		obj.push();
		    break;
 	    }
	   	case 2:{
    		obj.pop();
		    break;
	    }
    	default :{
    		cout<<"Select Appropriate choice"<<endl;
		    break;
	    }
	}
}
int perform_operation2(SingleStack *p,int choice){
    switch(choice){
	    case 1:{
        	(*p).push();
	       	break;
		}
		case 2:{
    		int temp=(*p).rec_queue();
		    if(temp!=-1)
		    cout<<"dequeue elememt is : "<<temp;
		    cout<<endl;
	        break;
	   	}
    	default:{
		    cout<<"Select appropriate choice"<<endl;
	     	break;
	    }
    } 	        
}
int main(){
	int choice = perform_choice();
	
	//through two stacks
	
	while(choice!=3){
		perform_operation1(choice);
	    choice = perform_choice();

    }
	
	
    //by single stack;
   /* SingleStack p;
    while(choice!=3){
    	perform_operation2(&p,choice);
        choice = perform_choice();
    }*/
}

