//you are given a k-sorted array and you need to merge them

#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
using tiii = tuple<int,int,int>;

class mycomp{
    public:
    bool operator()(tiii a, tiii b){
        return get<0>(a) > get<0>(b);
    }
};

void mergeAndPrint(int** arr, int row, int col){

    priority_queue<tiii, vector<tiii> ,mycomp> minheap;
    
    for(int i=0;i<row;i++){
        minheap.push(make_tuple(arr[i][0], i,0));
    }

    int totalElements = row*col;
    while(totalElements--){
        tiii topTuple = minheap.top();
        minheap.pop();    
        int el = get<0>(topTuple);
        int rowNo = get<1>(topTuple);
        int colNo = get<2>(topTuple);
        cout<<el<<" ";
        if(colNo+1 < col){
            minheap.push(make_tuple(arr[rowNo][colNo+1], rowNo,colNo+1));
        } 
    }
}

int main(){

    int narr;//this is k
    cin>>narr;

    int size;
    cin>>size;

    int** arr = new int*[narr];
    for(int i=0;i<narr;i++){
        arr[i] = new int[size];
        for(int j=0;j<size;j++){
            cin>>arr[i][j];
        }
    }
        // 4 4
        // 2 3 4 5
        // 1 5 7 8
        // 2 3 7 9
        // 3 6 7 9


    // merge k-sorted array
    mergeAndPrint(arr,narr, size);

return 0;
}