#include<iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream infile("in2.txt");
ofstream outfile("out2.txt");

int no_of_bits(int n){
	int temp=n;
	int count=0;
	while(temp){
		count++;
		temp=temp>>1;
	}
	return count;
}

int create_mask(int m,int i,int j){
	int count=no_of_bits(m)-1;
	int mask=0;
	int temp=m;
	
	while(temp){
		mask=mask<<1;
		if(count>=i && count<=j){
			mask=mask|0;
		}
		else
		mask=mask|1;
		temp=temp>>1;
		count--;
	}
	return mask;
}

void bit_conversion(int n){
	if(n==0)
	return ;
	int bit=n&1;
	n=n>>1;
	bit_conversion(n);
	outfile<<bit;
}
int replace(int m,int n,int i,int j){
	
	int count = no_of_bits(n);
	
	if(count>(j-i+1)){
	    return -1;
	}
	
	if(i<(j-count+1))
	i=j-count+1;
	
	int mask,temp=m;
	mask = create_mask(m,i,j);
	temp = temp&mask;
	n = n<<i;
	temp = temp|n;
	return temp; 
}
int main(){
	if(!infile){
		cout<<"File is missing";
		return 0;
	}
	int t;
	infile>>t;
	while(t--){
		int n,m;
		infile>>m>>n;
		int i,j;
		infile>>i>>j;
		int result=replace(m,n,i,j);
		outfile<<result;
		
		if(result!=-1)
		outfile<<" : ",bit_conversion(result);
		outfile<<endl;
	}
}
