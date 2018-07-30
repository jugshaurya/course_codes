#include <iostream>
#include<climits>
using namespace std;

void selection_sort(int *arr, int n){

    for(int i=0;i<n-1;i++){
        int mini = INT_MAX;
        int index = -1;
        for(int j=i;j<n;j++){
            if(arr[j]<mini){
                index = j;
                mini = arr[j];
            }
        }
        swap(arr[i], arr[index]);
    }
}


int main() {
    // cout<<"Hello World!";
    int n;
    cin>>n;

    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selection_sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
