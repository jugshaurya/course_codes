#include <iostream>
#include<string>
#include<algorithm> //--for is_permutation()
using namespace std;

bool isPermutation(string a, string b){

    //using freq array
    int arr[26]{};
    for(int i = 0;a[i]!='\0';i++){
        arr[a[i] -'a']++; 
    }

    for(int i = 0; b[i]!='\0';i++){
        arr[b[i] -'a'] --; 
    }

     for(int i = 0;i<26 ;i++){
        if(arr[i] !=0){
            return false;
        }
    }
    return true;
}

int main() {
    string a ;
    cin>>a;
    string b;
    cin>>b;

    //==============Stl version========================

     if(is_permutation(a.begin(), a.end(), b.begin())){
         cout<<"Yes"<<endl;
     }else{
         cout<<"No"<<endl;
     }    


     //=============My Version=================

    cout<< boolalpha << isPermutation(a,b);

}
