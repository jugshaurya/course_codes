//to find an element in a rotated sorted array

#include <iostream>
using namespace std;


int search(int* arr,int size,int key, int start, int end){
    
    if(start>end){
        return -1;
    }
    
    int mid = (start+end)/2;
    
    if(arr[mid] == key){
        return mid;
    }

    //mid lies in--left part
    if(arr[mid] >= arr[start]){
        if(arr[start]>=key && arr[mid]<key){
            return search(arr,size,key,start,mid-1);
        }else{
            return search(arr,size,key,mid+1,end);
        }
    }
    
    //mid lies in--right part
    if(arr[mid]<key && arr[end]>=key){
        return search(arr,size,key,mid+1,end);
    }else{
        return search(arr,size,key,start,mid-1);
    }
}


int main() {
    int arr[] = {4,5,1,2,3};
    int size = sizeof(arr)/sizeof(int);
    
    int key = 7;
    
    cout<<search(arr, size, key, 0, size-1);
    
}
