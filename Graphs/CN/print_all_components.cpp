/*
    Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
    V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
    E is the number of edges present in graph G.
    You need to take input in main and create a function which should return all the connected components. 
    And then print them in the main, not inside function.
    Print different components in new line. And each component should be printed in increasing order
     (separated by space). Order of different components doesn't matter.
*/

#include <iostream>
#include <map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

void addEdge(int u, int v, int**edges){
    edges[u][v] = 1;
    edges[v][u] = 1;
}

void BFS_comp(int** edges, int n, vector<int>* ans, int size,int sp,bool* visited){
    queue<int> q;
    q.push(sp);
    visited[sp] = true;
    while(!q.empty()){
        int front = q.front();
        // cout<<front<<" ";
        ans[size].push_back(front);
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[front][i]==1){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void printAllComp(int** edges, int n, vector<int>* ans, int& size){
    bool * visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            BFS_comp(edges,n,ans,size,i,visited);
            size++;
        }
    }

    delete [] visited;
}

int main() {
    int V, E;
    cin >> V >> E;

  	int** edges = new int*[V];
  	for(int i=0;i<V;i++){
    	edges[i] = new int[V];
        for(int j=0;j<V;j++){
            edges[i][j] = 0;
        } 
    }

    int u,v;
    for(int i=0;i<E;i++){
        cin>>u>>v;
        addEdge(u,v,edges);
    }
  
   vector<int>* ans =  new vector<int>[V];
   int size = 0;
   printAllComp(edges,V,ans,size);


    // sort + print 
    for(int i=0;i<size;i++){
        vector<int> temp = ans[i];
        int sze = temp.size();
        sort(temp.begin(),temp.end());
        for(int j=0;j<sze;j++){
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }

    delete [] ans;
    for(int i=0;i<V;i++){
        delete [] edges[i];
    }
    
    delete [] edges;

  return 0;
}
