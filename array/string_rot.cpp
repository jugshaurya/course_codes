#include <iostream>
#include<cstring>
using namespace std;

char* rotate(char str[], int n){
    
    int length = strlen(str);
    // cout<<length;

    for(int i = length; i<length+n;i++){
        str[i] = str[i-length];
    }
    str[length+n] = '\0';
    str = str + n;
    return str;
}   

int main() {
    // cout<<"Hello World!";
   
    char str[100];
    cin.getline(str,100);
     int n;
    cin>>n;

    cout<<rotate(str,n);
}
