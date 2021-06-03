#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int MAX=100000;

int gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
   bool visited[n][m]={false};
    int count=0;
    for(int i=0; i<k; i++){
        int row=track[i][0]-1;
        int col1=track[i][1]-1;
        int col2=track[i][2]-1;
        for(int j=col1; j<=col2; j++){
            if(!visited[row][j])
            count++;
            visited[row][j]=true;
        }
    }
    int total=n*m;
    return (total-count);
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> vec;
    for(int i=0; i<k; i++){
        int row,col1,col2;
        vector<int> v;
        cin>>row>>col1>>col2;
        v.push_back(row);
        v.push_back(col1);
        v.push_back(col2);
        vec.push_back(v);
        v.clear();
    }
    cout<<gridlandMetro(n,m,k,vec);
}

