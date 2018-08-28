#include<iostream>
#include<vector>
using namespace std;

class minHeap{
    void heapify(int);
public:
    vector<int> v;
    minHeap(){
        v.push_back(-1);  // starting indexing from 1
    }

    void push(int data);
    void pop(); //pop the minimum element
    int top();
    bool empty();
    int size();
    void print(){
        int n =  v.size();
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};

void minHeap::heapify(int index){

    int lchild = 2*index;
    int rchild = 2*index + 1;
    int size = v.size() - 1;
    int minIndex = index;

    if(lchild <=size && v[lchild] < v[minIndex]){
        minIndex = lchild;
    }

    if(rchild <=size && v[rchild] < v[minIndex]){
        minIndex = rchild;
    }
    
    if(minIndex != index){
        swap(v[index], v[minIndex]);
        return heapify(minIndex);
    }
}

void minHeap::push(int data){
    v.push_back(data);
    int index = v.size() - 1;
    int parent = index/2;
    while(parent>=1 && v[parent]> v[index]){
        swap(v[parent], v[index]);
        index = parent;
        parent = index/2;
    }
}

void minHeap::pop(){
    if(empty()){
        return ;
    }

    int last = v.size() - 1;
    swap(v[1],v[last]);
    v.pop_back();
    heapify(1);
}

int minHeap::top(){
    if(empty()){
        cout<<"heap is empty ";
        return -1;
    }

    return v[1];
}

bool minHeap::empty(){
    return v.size() == 1;
}

int minHeap::size(){
    return v.size() - 1;
}

int main(){
    minHeap obj;
    // 54 7 8 0 4 2 6 3 
    obj.push(54);   obj.push(7);
    obj.push(8);    obj.push(0);
    obj.push(4);    obj.push(2);
    obj.push(6);    obj.push(3);
    
    cout<<"My  HEAP Array"<<endl;;
    obj.print();

    cout<<"HEAP SORT"<<endl;
    while(!obj.empty()){
        cout<<obj.top()<<" ";
        obj.pop();
    }
}