#include<iostream>
#include<bits/stdc++.h>
using namespace std;
ofstream outfile("out2.txt");

int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		long total=0;
		int length=str.length();
		for(int i=0; str[i]!='\0'; i++){
			if(str[i]=='1')
			total=total+pow(2,length-i-1);
		}
		outfile<<total<<endl;
	}
}
