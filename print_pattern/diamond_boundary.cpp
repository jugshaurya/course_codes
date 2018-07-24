#include <iostream>
using namespace std;
int main() {
    // cout<<"Hello World!";
    int n;
    cin>>n;

    n= 2*n-1;
    for(int i=0;i<n;i++){
        cout<<"*";
    }
    cout<<endl;

    int denom = 2;
    for(int i=1;i<n-1;i++){
        // cout<<denom<<endl;
        for(int j = 0;j<n/denom;j++){
            cout<<"*";
        }

        for(int j = 0;j< (n-(n/denom)-(n/denom));j++){
            cout<<" ";
        }

        for(int j = 0;j<n/denom;j++){
            cout<<"*";
        }

        if(i<n/2){
            denom++;
        }else{
            denom--;
        } 
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<"*";
    }
    cout<<endl;
}
