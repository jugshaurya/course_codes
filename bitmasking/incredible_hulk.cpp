// 
// The Planet Earth is under a threat from the aliens of the outer space and the Marvel Avengers 
// team is busy fighting against them. Meanwhile, The Incredible Hulk has to defeat an enemy who is N steps
 // above the level where he is standing (assume it as the 0th level). Hulk, because of his incredible jumping
  // ability can take jumps in power of 2. In order to defeat the enemy as quickly as possible he has to reach
 // the Nth step in minimum moves possible. Help Hulk to find the same and contribute in saving the Mother Earth.

#include <iostream>
using namespace std;

int nu_set_bits(int n){

    int count =0 ;
    while(n>0){
        count++;
        n=n&(n-1);
    }
    return count;
}


int main() {
    // cout<<"Hello World!";
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        cout<<nu_set_bits(n)<<endl;
    }
}
