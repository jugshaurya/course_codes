// KTH_LARGEST
// Find k largest elements in an array.

#include<iostream>
#include<queue>
using namespace std;
int main() {
    priority_queue<int, vector<int> ,greater<int> > minheap;
    int n;
    cin>>n;
    
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int k;
    cin>>k;
    
    //build heap
    for(int i=0;i<k;i++){
        minheap.push(arr[i]);
    }
    
    for(int i=k;i<n;i++){
        if(arr[i] > minheap.top()){
            minheap.pop();
            minheap.push(arr[i]);
        }
    }
    
    cout<<minheap.top();   
	return 0;
}