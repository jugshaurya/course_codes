//stl to implement heap
#include <iostream>
#include<queue> //--> queue have a class called priority queue which is maxheap
#include<functional> //->> for greater<int>();
using namespace std;

class mycompclass{
public:
    bool operator()(int a, int b){
        return a>b;//a>b will sort in increasing order
        // while a<b will do in desending order.
    }
};

int main() {
    // cout<<"Hello World!";

    int arr[] ={3,4,5,4,213,56,6,7,8,0};
    int n = sizeof(arr)/sizeof(int);

    priority_queue<int> pq;  //inbuilt max heap
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }

    while(!pq.empty()){
        cout << pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    priority_queue<int, vector<int>, mycompclass> minheap;//min heap
    for(int i=0;i<n;i++){
        minheap.push(arr[i]);
    }

    while(!minheap.empty()){
        cout << minheap.top()<<" ";
        minheap.pop();
    }
}
