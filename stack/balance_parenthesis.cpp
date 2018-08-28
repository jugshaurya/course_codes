#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isBalanaceParen(string str){
	stack<char> s;
	int len = str.size();
	for(int i = 0;i<len;i++){
		if(str[i]=='(' || str[i]=='{' ||str[i]=='['){
			s.push(str[i]);
		}else if(str[i]==')' || str[i]=='}' ||str[i]==']'){
            char ch;
            if(!s.empty())
            	ch = s.top();
            else
            	return false;
            switch(str[i]){
                case ')':
                    if(ch == '(') s.pop();
                    else return false;
                    break;
                
                case '}':
                    if(ch == '{') s.pop();
                    else return false;
                    break;
                
                
                case ']':
                    if(ch == '[') s.pop();
                    else return false;
                    break;
            }
        }
	}
	
	return s.empty();
}

int main(){

	string str = "[{a-(b+c)} - {d*(e+f)}]";
	cout<<boolalpha<<isBalanaceParen(str);
    cout<<endl;

	string str1 = "[{a-(b+c)} - {d*(e+f)]";
	cout<<boolalpha<<isBalanaceParen(str1);
}