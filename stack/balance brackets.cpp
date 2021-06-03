#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool balance(string str){
	stack<char> s;
	for(int i=0; str[i]!='\0'; i++){
		if(str[i]=='{' || str[i]=='[' || str[i]=='('){
			s.push(str[i]);
		}
		else{
			if(str[i]==']')
			    if(s.top()!='[')
			    return false;
			else if(str[i]=='}')
			    if(s.top()!='{')
			    return false;
			else if(str[i]==')')
			    if(s.top()!='(')
			    return false;
			s.pop();
	    }
	}
	if(!s.empty())
	return false;
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		bool result=balance(str);
		if(result==true)
		cout<<"Valid";
		else
		cout<<"Invalid";
		cout<<endl;
	}
}
