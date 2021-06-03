#include<iostream>
#include<bits/stdc++.h>
#define vect vector<int> // define vector int as macro 
using namespace std;

ifstream infile("in2.txt");
ofstream outfile("out2.txt");

vect store_array(int n){
	vect vec;
	int temp=n;
	int value=0;
	//i will check does 8 bit complete or not 
	int i=-1;
	
	while(temp!=0){
		i++;
		int bit=temp&1;
		if(bit==1){
			value=value+pow(2,i);
		}
		// if i+1 is equal to 8 bit then we store it in vector
		if((i+1)%8==0){
			// let value is 85 ==> 01010101 in bits
			//thus it will store as 1010101
			vec.push_back(value);
			cout<<value;
			value=0;
			//now it check for next 8 bits
			i=-1;
		}
		temp=temp>>1;
	}
	//if some value remains to push back
	if(value!=0){
		vec.push_back(value);
		value=0;
	}
	return vec;
}
//this function form the each 8bit number as order
//first value in vectro form as most significant 8bits
void recursion(int *result,int temp){
	if(temp==0)
	return ;
	int bit=temp|0;
	temp=temp>>1;
	recursion(result,temp);
	*result=(*result)|bit;
	*result=(*result)<<1;
}

//this function only number to in bit form as 14 = 1110
void convert_bits(int result){
	if(result==0)
	return ;
	int bit=result&1;
	result=result>>1;
	convert_bits(result);
	outfile<<bit;
}

//function forms the endian conversion
int conversion(int n){
	vect vec;
	int result=0;
	vec=store_array(n);
	int length=vec.size();
	for(int i=0; i<length; i++){
		int temp=vec[i];
		recursion(&result,temp);
		
	}
	result=result>>1;
	return result;
	
}

int main(){
	if(!infile)
	{
		cout<<"file is missing";
		return 0;
	}
	int t;
	infile>>t;
	while(t--){
		int n;
		infile>>n;
		
		int result=conversion(n);
		outfile<<result<<endl;
		
		//to check in bits for proper understanding
		/* 
		//bits conversion of original number
		convert_bits(n);
		outfile<<endl;
		
		// bits conversion of endian conversion number
		convert_bits(result);
    	outfile<<endl;
    	*/
	}
}
