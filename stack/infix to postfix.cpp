#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int precedence(char op){
	if(op=='^')
	return 3;
	if(op=='*' || op=='/')
	return 2;
	if(op=='+' || op=='-')
	return 1;
}

void infixPostfix(string str){
	stack<char> s;
	for(int i=0; str[i]!='\0'; i++){
		if(str[i]>=97 && str[i]<=122 )
		cout<<str[i];
		else if(str[i]=='(')
		s.push(str[i]);
		else if(str[i] == ')')
		{
			while(s.top()!='(')
			{
				cout<<s.top();
				s.pop();
			}
			s.pop();
		}
		else{
			while(!s.empty() && precedence(str[i])<precedence(s.top()) && s.top()!='(')
			{
				cout<<s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}

int main(){
    int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		infixPostfix(str);
		cout<<endl;
	}	
}
