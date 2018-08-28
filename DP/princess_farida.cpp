/*
	Princess FARIDA
	
	Once upon time there was a cute princess called Farida living in a castle with her father, mother and uncle. 
	On the way to the castle there lived many monsters. Each one of them had some gold coins. Although they are 
	monsters they will not hurt. Instead they will give you the gold coins, but if and only if you didn't take any 
	coins from the monster directly before the current one. To marry princess Farida you have to pass all the monsters
	and collect as many coins as possible. Given the number of gold coins each monster has, 
	 the maximum number of coins you can collect on your way to the castle.
*/

#include <iostream>
using namespace std;

long maxCoinFromMonster(int* arr, int n, long* memo){

    if(n==0){
        return 0;
    }

    if(n==1){
        return arr[0];
    }

    if(memo[n]!=-1){
        return memo[n];
    }

    long option1 = arr[0] + maxCoinFromMonster(arr+2, n-2, memo);
    long option2 = maxCoinFromMonster(arr+1, n-1, memo);
    return memo[n] = max(option1, option2); 
}

//dp

long maxCoinFromMonster_DP(int* arr, int n){
    long* memo = new long[n+1];
    fill(memo, memo+n+1, -1);
    memo[0] = 0;
    memo[1] = arr[0];

    for(int i=2;i<=n;i++){
        long option1 = arr[i-1] + memo[i-2];
        long option2 = memo[i-1];
        memo[i] = max(option1, option2);
    }

    return memo[n];
     delete [] memo;
}

int main() {
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int  n;
        cin>>n;
        int* arr = new  int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        long* memo = new long[n+1];
        fill(memo, memo+n+1, -1);
        
        cout<<"Case "<<i+1<<": "<<maxCoinFromMonster(arr,n, memo)<<endl;
        delete [] arr;
        delete [] memo;
    }
}
