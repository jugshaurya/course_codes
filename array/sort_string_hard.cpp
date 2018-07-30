// Given a list of 'n' strings S0,S1,S2,……,Sn-1, each consisting of digits and spaces, the number of spaces is the same for each entry, the goal is to implement a variation of a sort command. None of the strings contains consecutive spaces. Also, no string starts with a space nor ends with it. 
// Spaces are used to divide string into columns, which can be used as keys in comparisons.

// The program has to support the required parameters:

// key: integer denoting the column used as a key in comparisons. 
// The left-most column is denoted by 1.

// reversed: boolean variable indicating whether to reverse the result of comparisons.

// comparison-type: either lexicographic or numeric. Lexicographic means that we use Lexicographical order
 // where for example (122 < 13) . Numeric means that we compare the strings by their numerical values, 
// so (13 < 122) . If the comparison type is 'numeric' and numeric values of keys of Si and Sj are equal 
// for i < j , then Si is considered strictly smaller than Sj because it comes first.

// Sample Input:
// 3
// 92 022
// 82 12
// 77 13
// 2 false numeric

// Sample Output:
// 82 12
// 77 13
// 92 022
#include <iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int key;
string reversed;
string type;

int strToInt(string str){
    int num = 0;
    int mulFactor=1;
    for (int i = str.length()-1; i >=0; i--) {
        num+= ((str[i]-'0')*mulFactor);
        mulFactor*=10;
    }
    return num;
}

bool mycomp(vector<string> v, vector<string> u){
    int value1 = strToInt(v[key-1]);
    int value2 = strToInt(u[key-1]);

    if(type=="numeric" && value1==value2){
        return value1<value2;
    }

    // return value1<value2;
    if(reversed=="true"){
        if(type == "numeric"){
            return value1 > value2;
        }else{
            return v[key-1] > u[key-1];
        }
    }else{
        if(type == "numeric"){
            return value1 < value2;
        }else{
            return v[key-1] < u[key-1];
        }
    }
}

int main() {

    int n;
    cin>>n;
    cin.ignore();

    vector<string>* arr =new vector<string>[n];
    for(int i=0; i<n; i++){
        string str;
        getline(cin, str);
        //tokenize my string
        char* value = strtok((char*)str.c_str(), " ");;
        while(value!=NULL){
            arr[i].push_back(string(value));
            value = strtok(NULL," ");
        }
    }    

    cin>>key>>reversed;
    cin>>type;

    sort(arr,arr+n, mycomp);
    for(int i=0;i<n;i++){
        vector<string> v = arr[i];
        int len = v.size();
        for(int i=0;i<len;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

}
