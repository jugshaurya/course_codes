
// question is after code
#include <iostream>
#include <climits>
using namespace std;
int main() {
    // cout<<"Hello World!";

    int t;
    cin>>t;
    while(t--){

        int c1,c2,c3,c4;
        cin>>c1>>c2>>c3>>c4;

        int n_rick, n_cab ;
        cin>>n_rick>>n_cab;

        int* rick = new int[n_rick];
        int* cab = new int[n_cab];

        for(int i=0;i<n_rick;i++){
            cin>>rick[i];
        }

        for(int i=0;i<n_cab;i++){
            cin>>cab[i];
        }

        //rickshaw
        int min_rick = INT_MAX;
        int money_rick = 0;
        for(int i=0;i<n_rick;i++){
            money_rick += min(rick[i]*c1,c2);
        }

        min_rick = min( money_rick, c3);

        
        //cab
        int min_cab = INT_MAX;
        int money_cab = 0;
        for(int i=0;i<n_cab;i++){
            money_cab += min(cab[i]*c1,c2);
        }

        min_cab = min( money_cab, c3);

        cout<< min(c4, min_cab + min_rick)<<endl;

        delete [] rick;
        delete [] cab;
    }
}

// HELP RAMU
// Ramu often uses public transport. The transport in the city is of two types:
 // cabs and rickshaws. The city has n rickshaws and m cabs, the rickshaws are numbered 
// by integers from 1 to n, the cabs are numbered by integers from 1 to m.

// Public transport is not free. There are 4 types of tickets:

// A ticket for one ride on some rickshaw or cab. It costs c1 ruppees;
// A ticket for an unlimited number of rides on some rickshaw or on some cab. It costs c2 ruppees;
// A ticket for an unlimited number of rides on all rickshaws or all cabs. It costs c3 ruppees;
// A ticket for an unlimited number of rides on all rickshaws and cabs. It costs c4 ruppees.

// Ramu knows for sure the number of rides he is going to make and the transport 
// he is going to use. He asked you for help to find the minimum sum of ruppees he will
 // have to spend on the tickets.


// Input Format:
// Each Test case has 4 lines which are as follows:

// The first line contains four integers c1, c2, c3, c4 (1 ≤ c1, c2, c3, c4 ≤ 1000) — 
// the costs of the tickets. The second line contains two integers n and m (1 ≤ n, m ≤ 1000) 
// — the number of rickshaws and cabs Ramu is going to use. The third line contains n integers ai
 // (0 ≤ ai ≤ 1000) — the number of times Ramu is going to use the rickshaw number i. The fourth line contains
  // m integers bi (0 ≤ bi ≤ 1000) — the number of times Ramu is going to use the cab number i.

