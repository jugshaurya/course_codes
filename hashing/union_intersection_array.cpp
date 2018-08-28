
#include<iostream>
#include<map>
using namespace std;

int main(){
    int arr1[] = {4 ,5 ,6, 7, 8};
    int arr2[] = {3, 6, 4, 8, 9};
    int n = sizeof(arr1)/sizeof(int);

    map<int,bool> m;
    
    //intersection
    cout<<"Intersection"<<endl;
    for(int i=0;i<n;i++){
        m.insert(make_pair(arr1[i],true));
    }

    for(int i=0;i<n;i++){
        if(m[arr2[i]]){
            cout<< arr2[i]<<" ";
        }
    }
    cout<<endl;
    //union
    //printing the map -->since map contains unique elemnts all common elemnts are removed automatically....
    cout<<"Union"<<endl;
    for(pair<int, bool> i:m){
        cout<<i.first<<" ";
    }
    cout<<"\n";

}






