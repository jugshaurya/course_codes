#include <iostream>
using namespace std;
int main() {
    // cout<<"Hello World!";
    int n;
    cin>>n;

    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int freq[3]={0};

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i =0;i<3;i++){
        for(int j=0;j<freq[i];j++){
            cout<<i<<endl;
        }
    }

}
