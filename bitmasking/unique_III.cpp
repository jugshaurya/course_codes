// We are given an array containg n numbers. All the numbers are present 
// thrice except for one number which is only present once
// Find the unique number. Only use - bitwise operators, and no extra space.

#include <iostream>
using namespace std;

int unique_3(int* arr,int n){
    
    int bitstorer[20];    //since n<10^5   min no. of bits required are log(10^5) = 5* 3.x <20
    for(int i=0;i<20;i++){
        bitstorer[i]=0;
    }
    
    for(int i=0;i<n;i++){
        int m = arr[i];
        int j=0;
        while(m>0){
            bitstorer[j++]+= (m&1);
            m = m>>1;
        }
    }
    for(int i=0;i<20;i++){
        bitstorer[i] = bitstorer[i]%3;
    }
    int ans = 0;
    for(int i=0;i<20;i++){
        ans+=bitstorer[i] *(1<<i) ;
    }

    return ans;
}

int main() {

    int n;
    cin>>n;
    
    int arr[100005];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<unique_3(arr,n);
    
    return 0;
}
