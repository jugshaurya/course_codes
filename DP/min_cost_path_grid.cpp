#include<iostream>
#include<climits>
using namespace std;

int min_cost_rec(int** input, int si, int sj, int ei, int ej){

	if(si==ei && sj==ej){
		return input[ei][ej];
	}

	if(si > ei || sj > ej){
		return INT_MAX;
	}

	int option1 = min_cost_rec(input, si+1, sj, ei, ej);
	int option2 = min_cost_rec(input, si+1, sj+1, ei, ej);
	int option3 = min_cost_rec(input, si, sj+1, ei, ej);

	return input[si][sj] + min(option1, min(option2, option3));
}

int min_cost_DP(int** input, int m, int n){
	int** dp = new int*[m];
	for(int i=0; i<m; i++){
		dp[i] = new int[n];
	}

	dp[m-1][n-1] = input[m-1][n-1];
	for(int i = m-2; i>=0;i--){
		dp[i][n-1] = input[i][n-1] + dp[i+1][n-1];
	}

	for(int j= n-2; j>=0 ;j--){
		dp[m-1][j] = input[m-1][j] + dp[m-1][j+1];
	}

	for(int i=m-2;i>=0;i--){
		for(int j = n-2;j>=0;j--){
			dp[i][j] = input[i][j] + min(dp[i+1][j] , min(dp[i+1][j+1], dp[i][j+1])); 
		}
	}

	int ans = dp[0][0];
	// free memory
	for(int i=0;i<m;i++){
		delete dp[i];
	}
	delete [] dp;

	return ans;
}

int main(){

	int r, c;
	cin>>r>>c;

	int** input = new int*[r]; 
	for(int i=0;i<r;i++){
		input[i] = new int[c];
		for(int j=0;j<c;j++){
			cin>>input[i][j];
		}
	}

	cout<<min_cost_rec(input,0,0,r-1,c-1)<<endl;
	cout<<min_cost_DP(input,r,c)<<endl;

}