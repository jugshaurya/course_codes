#include <iostream>
#include<string>
using namespace std;

string reverse_str(string str){

    //not required btw
    if(str.length() == 0){
        return " ";
    }

    if(str.length() == 1){
        return str;
    }

    string small_reverse = reverse_str(str.substr(1));
    return small_reverse + str[0];
}

int main() {
    string reverse ;
    cin>>reverse;

    cout<<reverse_str(reverse);
}
