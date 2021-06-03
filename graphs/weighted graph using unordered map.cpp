#include<iostream>
#include<unordered_map>
#include<list>
#include<bits/stdc++.h>
#include<cstring>
#include<iterator>
using namespace std;
class graph{
	unordered_map<string,list<pair<string,int>>> l;
	public:
		void addEdge(string x,string y,bool bidir,int wt){
			l[x].push_back(make_pair(y,wt));
			if(bidir==true){
				l[y].push_back(make_pair(x,wt));
			}
		}
		void printGraph(){
			
			for(auto city:l)
			{
				string curr=city.first;
				cout<<curr<<"-> ";
				list<pair<string,int>> curbs=city.second;
				for(auto p:curbs){
					string dest=p.first;
					int wei=p.second;
					cout<<"("<<dest<<","<<wei<<"),";
				}
				cout<<endl;
			}
		}
};
int main(){
	graph gh;
	gh.addEdge("surat","bombay",1,250);
	gh.addEdge("delhi","bombay",0,1550);
	gh.addEdge("hyderabad","bombay",0,850);
	gh.addEdge("ahemdabad","bombay",0,550);
	gh.addEdge("surat","ahemdabad",1,200);
	gh.addEdge("surat","kurukshetra",0,1350);
	gh.addEdge("banglore","delhi",0,2250);
	gh.addEdge("banglore","ahemdabad",1,1750);
	gh.addEdge("gurgaon","delhi",1,450);
	gh.addEdge("kolkata","hyderabad",0,950);
	gh.addEdge("guwahati","bombay",1,3250);
	gh.addEdge("guwahati","kolkata",0,1650);
	gh.addEdge("trichy","bombay",1,1550);
	gh.addEdge("ahemdabad","trichy",0,1850);
	gh.printGraph();
	
}
