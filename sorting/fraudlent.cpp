#include <bits/stdc++.h>

using namespace std;



// Complete the activityNotifications function below.
int activityNotifications(vector<int> vec, int d) {
    long n=vec.size();
    vector<int> arr;
    vector<int> med;
    vector<int> temp; 
    
    for(int i=0; i<d-1; i++)
    temp.push_back(vec[i]);
    int i=d-1;   
	 
	while(i<n-1){
    	cout<<i<<" ";
    	temp.push_back(vec[i]);
    	arr.clear();
        arr=temp;
       
        sort(arr.begin(),arr.end());
        
        if(d%2==0){
            int value1=arr[d/2]+arr[(d/2)-1];
            med.push_back(value1);
        }
        else
        med.push_back(arr[(d-1)/2]);
        arr.clear();
        temp.erase(temp.begin());
        i++;
    }
    int count=0;
    cout<<count;
    cout<<med.size();
    for(int i=d; i<n; i++){
        if(d%2==0){
            if(vec[i]>=med[i-d])
            count++;
        }
        else {
            if(vec[i]>=(2*med[i-d]))
            count++;
        }
    }
    return count;

}

int main()
{
    int n,d;
    cin>>n>>d;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int value;
        cin>>value;
        arr.push_back(value);
    }
    cout<<activityNotifications(arr,d)<<endl;
    return 0;
}


