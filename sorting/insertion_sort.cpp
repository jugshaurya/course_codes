#include <iostream>
#include<climits>
using namespace std;

void selection_sort(int *arr, int n){

    for(int i=1;i<n;i++){
        for(int j = i; j>=0; j--){
            if(arr[j-1] <= arr[j]){
                break;
            }else{
                swap(arr[j], arr[j-1]);
            }
        }
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
