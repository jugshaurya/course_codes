//highest element in sorted rotated arrray

#include <iostream>
using namespace std;

int highest(int* arr, int size, int start, int end){

    int mid = (start+end)/2;
    
    if((mid+1)<=end && arr[mid]>arr[mid+1]){
        return mid;
    }
    
    if((mid-1)>=0 && arr[mid]<arr[mid-1]){
        return mid-1;
    }
    
    if(arr[start]<arr[mid]){
        return highest(arr,size,mid+1,end);
    }
    
    if(arr[end]>arr[mid]){
        return highest(arr,size,start,mid-1);
    }
}

int main() {
    
    int arr[] = {4,6,8,9,11,2,3};
    int size = sizeof(arr)/sizeof(int);
    
    cout<<highest(arr,size,0,size-1);
}
