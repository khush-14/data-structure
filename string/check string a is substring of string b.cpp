#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool by_array(string str1,string str2){
	int arr[26]={0};
	int Arr[26]={0};
	for(int i=0; str1[i]!='\0'; i++)
	{
		if(str1[i]>=97 && str1[i]<=122)
		arr[str1[i]-97]++;
		if(str1[i]>=65 && str1[i]<=90)
		Arr[str1[i]-65]++;
	}
	for(int i=0; str2[i]!='\0'; i++){
		if(str2[i]>=97 && str2[i]<=122){
		    if(arr[str2[i]-97]>0)
		    arr[str2[i]-97]--;
		    else
		    return false;
		}
		else{
			if(Arr[str2[i]-65]>0)
			Arr[str2[i]-65]--;
			else
			return false;
		}
	}
	for(int i=0; i<26; i++){
		if(arr[i]!=0 || Arr[i]!=0)
		return false;
	}
	return true;
}
bool by_sorting(string str1,string str2){
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	if(str1.length()!=str2.length())
	return false;
	
	for(int i=0; str1[i]!='\0'; i++)
	{
		if(str1[i]!=str2[i])
		return false;
	}
	return true;
}
int main(){
	ifstream infile("in3.txt");
	ofstream outfile("out3.txt");
	if(!infile)
	cout<<"File is missing"<<endl;
	int t;
	infile>>t;
	while(t--){
		string str1,str2;
		infile>>str1;
		infile>>str2;
		
		bool result=by_array(str1,str2);
		if(result==true)
		outfile<<"YES"<<" by array"<<endl;
		else
		outfile<<"NO"<<" by array"<<endl;
		
		result=by_sorting(str1,str2);
		if(result==true)
		outfile<<"YES"<<" by sorting"<<endl;
		else
		outfile<<"NO"<<" by sorting"<<endl;
		outfile<<endl;
		
		
	}
}
/*
expected output:
YES
NO 
NO
YES
NO
*/
