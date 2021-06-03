#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile ("in1.txt");
ofstream outfile("out1.txt");
int n_length(long n){
	int length=0;
	int temp=n;
	while(temp!=0){
		length++;
		temp=temp>>1;
	}
	return length;
}
int n_complexity(long n){
	int temp=n;
	int count_0=0,total=0,pos_0=-1,max=-1,pos_bit;
	if(temp==0)
	return 1;
	int i=0;
	int length=n_length(n);
//	cout<<length<<endl;
	while(temp && i<=length){
		int value=temp&1;
	//	cout<<value;
		if(value==1)
		total++;
		else if(value==0){
			count_0++;
			
    		if(count_0==1){
	    		pos_0=i;
		    	total++;
    		}
	    	else if(count_0>1) {
		    	
		    	count_0=1;
			    total=i-pos_0;
  			    pos_0=i;
	   	    }
	   	}
		i++;
		temp=temp>>1;
		if(max<total){
			pos_bit=pos_0;
		    max=total;
	    }
	//	cout<<max<<" ";
		
	}
	if(max<total){
		pos_bit=pos_0;
		max=total;
    }
     cout<<endl;
    return pos_bit;
   
}

int main(){
	if(!infile){
		cout<<"File missing";
		return 0;
	}
	int t;
	infile>>t;
	while(t--){
		long n;
		infile>>n;
		int bit=n_complexity(n);
		outfile<<bit<<endl;
	}
	
}
