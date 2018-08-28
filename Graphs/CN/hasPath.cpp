/*Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path 
between them or not. Print true or false.  V is the number of vertices present in graph G and vertices 
are numbered from 0 to V-1. E is the number of edges present in graph G*/

#include<iostream>
using namespace std;

bool hasPathUsingDFS(int** mat, int n, int v1, int * visited, int v2){
	visited[v1] = 1;
  bool ans  = false;
	for(int i=0; i<n; i++){
		if( (!visited[i]) && (mat[v1][i] == 1)){
			if(i == v2){
				return true;
			}
			ans = ans || hasPathUsingDFS(mat, n, i, visited, v2);
		}
	}
  
  return ans;

}



int main(){

	int n, e;
	cin>>n>>e;

	int** mat = new int*[n];
	for(int i=0;i<n;i++){
		mat[i] = new int[n];
		for(int j=0;j<n;j++){
			mat[i][j] = 0;
		}
	}

	for(int i=0;i<e;i++){
		int src, dest;
		cin>>src>>dest;
		mat[src][dest] = mat[dest][src] = 1;
	}

	int v1,v2;
	cin>>v1>>v2;
	int* visited = new int[n];
	for(int i=0;i<n;i++){
		visited[i] = 0;
	}
  
	cout <<boolalpha << hasPathUsingDFS(mat, n, v1, visited, v2);


	//free memory
	for(int i=0;i<n;i++){
		delete mat[i];
	}

	delete [] mat;
	delete [] visited;
}