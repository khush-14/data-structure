#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(int k,int arr[]){
	for(int i=k/2-1; i>=0; i--)
	{
		int parent=i;
		if(2*i+1<=(k-1)){
			if(arr[2*i+1]>arr[parent])
			parent=2*i+1;
		}
		if(2*i+2<=(k-1)){
			if(arr[2*i+2]>arr[parent])
			parent=2*i+2;
		}
		if(parent!=i){
			swap(&arr[parent],&arr[i]);
		}
	}
}

int find_result(int arr[],int n,int k){
	heapify(k,arr);
	for(int i=k; i<n; i++){
		if(arr[i]<arr[0])
		{
			swap(&arr[0],&arr[i]);
			heapify(k,arr);
		}
	}
	return arr[0];
}

int partition(int l,int r,int arr[]){
	int pivot=arr[r];
	int i=l-1;
	for(int j=l; j<r; j++)
	{
		if(pivot>=arr[j])
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[r]);
	return i+1;
}

int find_quick(int arr[],int r,int k,int l){
	int p;
	if(k>0 && k<=r-l+1){
		p=partition(l,r,arr);
		if(p-l==k-1)
		return arr[p];
		if(p-l>k-1)
		return find_quick(arr,p-1,k,l);
		else
		return find_quick(arr,r, k - p + l - 1,p+1);
	}
}
int main(){
	ifstream infile("in2.txt");
	ofstream outfile("out2.txt");
	if(!infile)
	cout<<"File is missing";
	int t;
	infile>>t;
	while(t--){
		int n,k;
		infile>>n>>k;
		int arr[n];
		for(int i=0; i<n; i++)
		infile>>arr[i];
//		outfile<<"Using Max_heap Considering k<=n"<<endl;
		outfile<<find_result(arr,n,k)<<" Max_heap"<<endl;
		
	//	outfile<<"Using quick_select"<<endl;
		outfile<<find_quick(arr,n,k,0)<<" quick_select"<<endl;
	}
}

/* expected output
6
1
3
0
*/
