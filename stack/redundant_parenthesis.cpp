#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool haveRedundantParen(string str){
    stack<char> s;
    int n = str.size();
    for(int i=0;i<n;i++){
        if(str[i] == ')'){
            if(s.empty()){
                return false;
            }else if(s.top() == '('){
                return true;
            }else{
                while(s.top() != '('){
                    s.pop();
                }
                s.pop();
            }
        }else{
            s.push(str[i]);
        }
    }
    return false;
}

int main(){

    string str = "((a+b)-(d-c))"; //no it doesn't have
    cout<<boolalpha<<haveRedundantParen(str);
    cout<<endl;

    string str1 = "((a+b)*((d-c)))";//yes it have
    cout<<boolalpha<<haveRedundantParen(str1);
}













