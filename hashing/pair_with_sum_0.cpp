
#include<iostream>
#include<map>
using namespace std;

int main(){
    int arr[] = {4 ,5 ,6, 7, -3, -4, -5, -6 ,3,3};
    int n = sizeof(arr)/sizeof(int);

    map<int,bool> m;

    for(int i=0;i<n;i++){
        int el = arr[i];
        if(m[-el]){
            cout<<el<<" , "<<(-el)<<endl;
            m.erase(-el);
            m.erase(el);
        }else{
            m.insert(make_pair(el,true));
        }
    }


    //version 2
    // for(int i=0;i<n;i++){
    //     int el = arr[i];
    //     if(m.count(-el)){
    //         cout<<el<<" , "<<(-el)<<endl;
    //     }else{
    //         m.insert(make_pair(el,true));
    //     }
    // }
    
}






