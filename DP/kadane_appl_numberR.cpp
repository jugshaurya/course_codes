/*
	Number Of R's
		As we all know RK loves his name very much especially the character 'R'
	 	so this time task for you is based on his awesome name. RK gives you a string S consisting of characters 'R' and
	 	'K' only. Now you are allowed to do exactly one move that is you have to choose two indices i and j (1<=i<=j<=|S|
	 	where |S| is string length ) and flip all the characters at position X where i<=X<=j. Flipping the character means 

	 	:	if S[X]='R' :  //If character at position X is 'R' then change it to 'K'
			  S[X]='K'  
			else :          //else if character at position X is 'K' then change it to 'R'
	 		 S[X]='R'
		
		Now your goal is that after exactly one move you have to obtain the maximum number of R's as RK loves this
		character very much. So help RK with maximum R's.
*/

#include<iostream>
using namespace std;

int kadane(string str){
    int n = str.length();
    int ms = 0;
    int cs = 0;

    for(int i=0; i<n; i++){
        if(str[i] == '1'){
            cs += 1;
        } else {
            cs += -1;
            if(cs < 0){
            cs = 0;
            }
        }
        ms = max(ms, cs);
    }

    return ms;
}

int maxR_s(string str){
    int n = str.length();

    int count = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == 'R'){
            str[i] = '0';
            count++;
        }
        else{
            str[i] = '1';        
        }
    }

    if(count == n){
        return n-1;
    }

    return count + kadane(str);

}

int main(){
	int t;
	cin>>t;

	while(t--){
		string str;
		cin>>str;

		cout<<maxR_s(str)<<endl;
	}
}