/*  longest incresing subsequence*/
/*  longest incresing subsequence*/
#include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int n){
	int* dp = new int[n];
	fill(dp, dp + n, 1);
	for(int i=1;i<n;i++){
		int maxi = 1;
		for(int j=0;j<i;j++){
			if(arr[j] < arr[i]){
				maxi = max(maxi, dp[j] + 1);
			}
		}
		dp[i] = maxi;
	}

    int maxi = INT_MIN;
	for(int i=0;i<n;i++){
        maxi = max(maxi, dp[i]);
	}
    
    delete [] dp;
    return maxi;
}	

int main(){
    int n;
    cin>>n;
    
	int *arr =new int[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	cout<<lis(arr,n); 
}
