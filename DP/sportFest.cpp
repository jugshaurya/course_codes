// Prateek Bhaiya decided to organize a sports fest for students of Coding Blocks and he came to 
// know that Cricket, Football and Hockey are popular in the same order. 
// So, he laid down the following rules for the fest :

// Only one match can be played in a single day.
// Cricket can be played daily.
// Footbal can't be played on two consecutive days.
// There must be a gap of at least two days between two hockey matches.
// Since Bhaiya is busy enjoying his Maggi, he wants you to write a program that can calculate 
// the number of ways the fest can be organised, given the number of days the fest is scheduled to be 
// organised over.

#include<iostream>
#include<string>
using namespace std;

#define MOD 1000000007
typedef long long ll;


class four{
public: 
	ll total ;
	ll c;
	ll f;
	ll h;

	four(){
		total=c=f=h=0;
	}

	four(ll t,ll c,ll f,ll h){
		total = t;
		this->c = c;
		this->f = f;
		this->h = h;
	}

};


ll sportFest(ll n){

	four dp[100005];
	dp[0] = four(0,0,0,0);
	dp[1] = four(3,1,1,1);

	for(ll i=2;i<=n;i++){
		ll cricket = dp[i-1].total;
		ll football = (dp[i-1].c + dp[i-1].h)%MOD;
		ll hockey = ((dp[i-1].total)%MOD -((dp[i-1].h + 2*(dp[i-2].h))%MOD)+MOD)%MOD;/*total-h at once place-(h at tens place*2) becoz after tensplace char we can either put f or c.*/
        ll sum = ((cricket + football)%MOD + hockey)%MOD;
		dp[i].total = sum;
		dp[i].c = cricket;
		dp[i].f = football;
		dp[i].h = hockey;
	}

	return dp[n].total;
}

int main(){

	ll n ;
    cin>>n;
	cout<<sportFest(n);
}