//stl to implement heap->using custom comparitor
#include <iostream>
#include<queue> //--> queue have a class called priority queue which is maxheap
#include<functional> //->> for greater<int>();
using namespace std;

class fruit{
public:
    string name;
    int price;
};

class comparePrice{
public:
    bool operator()(fruit a, fruit b){
        return a.price > b.price;
    }
};

class compareName{
public:
    bool operator()(fruit a, fruit b){
        return a.name > b.name;
    }
};

int main() {
    // cout<<"Hello World!";

    fruit arr[] = {
                    {"apple",150},{"banana",40},{"pomegranate",120},
                    {"mango",80},{"strawberry",55},{"papaya",40}
                };
    int n = sizeof(arr)/sizeof(fruit);

    priority_queue<fruit, vector<fruit>, compareName> cn;
    priority_queue<fruit, vector<fruit>, comparePrice> cp;

    for(int i=0;i<n;i++){
        cp.push(arr[i]);
        cn.push(arr[i]);
    }

    while(!cn.empty()){
        cout << cn.top().name <<" "<<cn.top().price<<" , ";
        cn.pop();
    }
    cout<<endl;
    
    while(!cp.empty()){
        cout << cp.top().name<<" "<< cp.top().price<<" , ";
        cp.pop();
    }
}
