//you are given a running stream of integers u need to tell the 
// k-largest element during query query is ddenoted using -1

#include<iostream>
#include<queue>
using namespace std;

class mycomp{
    public:
    bool operator()(int a , int b){
        return a>b;
    }
};

void print(priority_queue<int, vector<int> ,mycomp> heap){
    while(!heap.empty()){
        cout<<heap.top()<<" ";
        heap.pop();
    }
    cout<<endl;
}

int main() {

    int n;
    cin>>n;

    int k;
    cin>>k;
    // we require min heap
    priority_queue<int, vector<int> ,mycomp> minheap;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        if(data == -1){
            print(minheap);
            continue;
        }

        if(minheap.size() < k){
            minheap.push(data);
        }else{
            int topel = minheap.top();
            if(topel < data){
                minheap.pop();
                minheap.push(data);
            }else{
                continue;
            }
        }
    }

}
