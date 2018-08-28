/*

	You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need 
	to figure out the total number of ways W, in which you can make change for Value V using coins of denominations
	D.
*/

#include<iostream>
using namespace std;

int countWaysToMakeChange(int* denominations, int numD, int value){
	if(numD == 0){
		return 0;
	}

	if(value == 0){
		return 1;
	}

    if(value < 0 ) {
        return 0;
    }

	int option1 = countWaysToMakeChange(denominations, numD, value - denominations[0]);
	int option2 = countWaysToMakeChange(denominations + 1, numD-1, value);

	return option2 + option1;
}


//dp
int countWaysToMakeChange_DP(int* denominations, int numD, int value){
    int** dp = new int*[numD+1];
    for(int i=0;i<=numD;i++){
        dp[i] = new int[value + 1];
    }

    for(int i=0;i<=value;i++){
        dp[0][i] = 0;
    }
    
    for(int i=0;i<=numD;i++){
        dp[i][0] = 1;
    }

    for(int i=1; i<=numD; i++){
        for(int j=1; j<=value; j++){
            dp[i][j] = dp[i-1][j] ;
            if(j>=denominations[i-1])
                dp[i][j] += dp[i][j-denominations[i-1]];
        }
    }
    
    return dp[numD][value];

}



int main(){
	int numD;
	cin>>numD;

	int* denominations = new int[numD];
	for(int i=0;i<numD;i++){
		cin >>denominations[i];
	}

	int value ;
    cin>>value;
	
    cout<<countWaysToMakeChange(denominations, numD, value)<<endl;
    cout<<countWaysToMakeChange_DP(denominations, numD, value)<<endl;
}