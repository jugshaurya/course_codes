#include<bits/stdc++.h>
using namespace std;

//recursion
int numberOfCodes(string str){
    int len = str.length();
    if(len == 0){
        return 1;
    }

    if(len == 1){
        return 1;
    }

    int ans = numberOfCodes(str.substr(1));
    int digit1 = str[0] -'0';
    int digit2 = str[1] -'0';
    int num = digit1 * 10 + digit2 ;
    if(num>=10 && num<=26){
        ans += numberOfCodes(str.substr(2));
    }

    return ans;
}

//top-down memoization
int numberOfCodes_memo(string str, int* memo){
    int len = str.length();
    if(len == 0){
        return 1;
    }

    if(len == 1){
        return 1;
    }

    if(memo[len] !=-1){
        return memo[len];
    }

    int ans = numberOfCodes_memo(str.substr(1), memo);
    int digit1 = str[0] -'0';
    int digit2 = str[1] -'0';
    int num = digit1 * 10 + digit2 ;
    if(num>=10 && num<=26){
        ans += numberOfCodes_memo(str.substr(2), memo);
    }
    
    return memo[len] = ans;
}

//bottom-up dp
int numberOfCodes_DP(string str){
    int l = str.length();
    int * dp = new int[l+1];
    dp[0] = 1;
    if(l>=1){
        dp[1] = 1;
        for(int i=2;i<=l;i++){
        	dp[i] = 0;
			if(str[i-1]!='0')
		        dp[i] = dp[i-1] % MOD;
            int digit1 = str[i-2] -'0';
            int digit2 = str[i-1] -'0';
            int num = digit1 * 10 + digit2 ;
            if(num>=10 && num<=26){
                dp[i] += dp[i-2];
            }
        }
    }

    int ans = dp[l];
    delete [] dp;
    return ans;
}

int main(){

    string n = "11111111111";

    int len = n.length();
    int* memo = new int[len+1];
    fill(memo, memo+len+1, -1);
    cout<<numberOfCodes_memo(n ,memo)<<endl;
    delete [] memo;

    cout<<numberOfCodes_DP(n)<<endl;

    cout<<numberOfCodes(n)<<endl;    
    return 0;
}












