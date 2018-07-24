//  Your task is simple, determine the minimum number of people required in
//  the room so that two have same birthday with probability greater than or equal 
//  to 'p'. (Assume there are 365 days in every year).

#include <iostream>
using namespace std;
int main() {
    // cout<<"Hello World!";
    float p;
    cin>>p;

    if(p==1){
        cout<<366<<endl;
        return 0;
    }

    float denom = 365;
    float num = 365;

    int peop = 0;
    float prob = 1.0;
    while((1 - prob) < p){
        prob *= (num--)/denom;
        peop++;
        // cout<<prob<<" "<<peop<<endl;
    }

    cout<<peop<<endl;
}
