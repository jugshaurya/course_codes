#include <iostream>
#include<string>
using namespace std;

int main() {
    string str ;
    cin>>str;

    int length = str.size();
    for(int i = 0; i<length; i++){
        for(int j = i; j<length; j++){
            for(int k = i; k<=j; k++){
                cout<<str[k];
            }
            cout<<endl;
        }
    }
}
