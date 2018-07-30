// DIVISIBLE SUBARRAYS
// You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.
// A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) 
// is divisible by N.


// Input Format:
// The first line contains the number of test cases T. First line of each test case contains an integer
 // N denoting the number of elements. Second line of each test case contains N integers, a1, a2, a3….aN, 
// here ai denotes the ith element of the array.

// Constraints:
// 1<=T<=10
// 1<=N<=10^5
// |ai|<=10^9

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int sum[100005] ={};
int freq[100005] ={};
int main() {
    
    int t;
    cin>>t; 
    
    while(t--){
        int n;
        cin>>n;
        
        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sum[0] = 0 ;
        for(int i=1;i<=n;i++){
            sum[i] = sum[i-1] + arr[i-1];
            sum[i] = sum[i] % n;
            sum[i] += n; //for handling negative numbers
            sum[i] = sum[i] % n;
        }
        
        for(int i = 0; i<n+1; i++){
            freq[i] = 0;
        }

        for(int i = 0; i<n+1; i++){
            freq[sum[i]]++;
        }

        long long ans = 0 ;
        for(int i=0;i<n;i++){
            ans += (long long)freq[i]*(freq[i]-1)/2;
        }

        cout<< ans <<endl;
        delete [] arr;
    }
    return 0;
}
