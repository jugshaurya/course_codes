/*
    1. Code : Get Path - DFS
    Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path 
    from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
    Find the path using DFS and print the first path that you encountered.

    Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
*/


/* 
    2. Code : Get Path - BFS
    Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from 
    v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
    Find the path using BFS and print the shortest path available.
    Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
*/
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void printPath_BFS(int** mat, int V, int src, int des){
    bool* visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;    
    }     

    int* parent = new int[V];
    queue<int> q;
    q.push(src);
    parent[src] = src;
    visited[src] = true;
    int front = q.front();
    while(!q.empty()){
        front = q.front();
        q.pop();        
        if(front == des){
            break;
        }else{
            for(int i=0;i<V;i++){
                if(!visited[i] && mat[front][i] == 1){
                    q.push(i);
                    visited[i] = true;
                    parent[i] = front;
                }
            }
        }
    }

    if(front == des){
        int temp = des;
        while(temp != src){
            cout<<temp<<" ";
            temp = parent[temp];
        }
        cout<<src;   
    }    

    delete [] visited;
}

vector<int> printPath_DFS(int** mat, int V, int src, int des, bool* visited){
    visited[src] = true;
    vector<int> v;
    if(src == des){
        v.push_back(des);
        return v;
    }

    for(int i=0; i<V; i++){
        if(!visited[i] && mat[src][i] == 1) {
            vector<int> vans = printPath_DFS(mat, V, i, des, visited);
            if(!vans.empty()){
                vans.push_back(src);
                return vans;
            }
        }
    }

    return v;
}

int main() {
    // cout<<"Hello World!";

    int V,e;
    cin>>V>>e;

    int** mat = new int*[V];
    for(int i=0; i<V; i++){
        mat[i] = new int[V];
        for(int j =0;j<V;j++){
            mat[i][j] = 0;
        }
    }

    int u, v;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    int src, des;
    cin>>src>>des;

    bool* visited = new bool[V];
    for(int i=0;i<V;i++){
       visited[i] = false;
   }

    vector<int> vans = printPath_DFS(mat, V , src, des, visited);
   for(auto i = 0; i<(int)vans.size(); i++){
       cout<<vans[i]<<" ";
   }

    printPath_BFS(mat, V, src,des);
    
    delete []visited;
    //delete mat..
}












