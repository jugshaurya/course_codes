#include<bits/stdc++.h>
using namespace std;

int fibonacci_rec(int n){
	if(n==0 || n==1){
		return 1;
	}
	return fibonacci_rec(n-1) + fibonacci_rec(n-2);
}

int fibonacci_memo(int n, int * memo){
	if(n==0 || n==1){
		return 1;
	}
	
	if(memo[n]!=-1){
		return memo[n];
	}	

	memo[n] = fibonacci_memo(n-1,memo) + fibonacci_memo(n-2, memo);
	return memo[n];
}

int fibonacci_DP(int n){
	int* dp = new int[n+1];
	dp[0] = 1;
	if(n>=1){
		dp[1] = 1;
		for(int i=2;i<=n;i++){
			dp[i] = dp[i-1] + dp[i-2];
		}	
	}

    int ans = dp[n];
    delete [] dp;
	return ans;
}

int fibonacci_I(int n){

	if(n==0 || n==1){
		return 1;
	}

	int arr[] = {1,1};
	for(int i=2;i<=n;i++){
		int nextNumber = arr[0] + arr[1];
		arr[0] = arr[1];
		arr[1] = nextNumber;
	}

	return arr[1];
}

int main(){

	int n = 6;
	cout<<fibonacci_rec(n)<<endl;
	int* memo = new int[n+1];
    memset(memo, -1, sizeof(int)* (n+1));
	cout<<fibonacci_memo(n,memo)<<endl;
	delete [] memo;
	cout<<fibonacci_DP(n)<<endl;
	cout<<fibonacci_I(n)<<endl;
}












