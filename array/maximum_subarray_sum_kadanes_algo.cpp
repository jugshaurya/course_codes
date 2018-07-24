//Maximum subarray sum

#include <iostream>
using namespace std;

int main() {
    // cout<<"Hello World!";

    int arr[] = {2,3,5,-1,5,3,-9,-5};
    int n = sizeof(arr)/sizeof(int);
    
    // method 1.--> O(n^3)
    int max_sum = 0; 
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum  = 0;
            for(int k =i; k<=j ;k++){
                sum += arr[k];
            }
            max_sum = max(max_sum, sum); 
        }
    }
    cout<<max_sum<<endl;

    // method 2.--> O(n^2)-->precomputation
    int* sum_arr = new int[n+1];
    sum_arr[0] = 0;
    for(int i=1;i<n+1;i++){
        sum_arr[i]  = sum_arr[i-1] + arr[i-1];
    }


    int max_sum2 = 0; 
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum  = 0;
            //we change this part of program
            // for(int k =i; k<=j ;k++){
            //     sum += arr[k];
            // }
            sum = sum_arr[j+1]- sum_arr[i];
            max_sum2 = max(max_sum2, sum); 
        }
    }
    cout<<max_sum2<<endl;
    delete [] sum_arr;

    //method 3 ->kadane's algo--> O(n)
    int cs = 0;
    int ms = 0;

    for(int i=0;i<n;i++){
        cs += arr[i];
        ms = max(ms,cs);
        if(cs<0){
            cs = 0;
        }
    }
    cout<<ms<<endl;
}
