/*  BFS and DFS traversel in case graph is disconnected as well*/

#include<iostream>
#include<queue>
using namespace std;

void printDFS(int** mat, int n, int sv, int * visited){
	cout << sv << " ";
	visited[sv] = 1;
	for(int i=0;i<n;i++){
		if( !visited[i] && mat[sv][i] == 1){
			printDFS(mat, n, i, visited);
		}
	}
}

void printBFS(int** mat, int n, int sv, int * visited){
	queue<int> q;
	q.push(sv);
    visited[sv]  = 1;
	while(!q.empty()){
		int topel = q.front();
		cout<<topel<<" ";
		for(int i=0; i<n; i++){
			if(!visited[i] && mat[topel][i] == 1){
                visited[i] = 1;                
                q.push(i);
			}
		}
		q.pop();
	}
}

void printDFS_DC(int** mat, int n){
	cout<<"DFS :"<<endl;
	int* visited = new int[n];
	for(int i=0;i<n;i++){
		visited[i] = 0;
	}

	for(int i=0; i<n; i++){
		if(!visited[i]){
			printDFS(mat, n, i, visited);
		}
	}
	cout<<endl;

	delete [] visited;
}

void printBFS_DC(int** mat, int n){

	cout<<"BFS :"<<endl;
	int* visited = new int[n];
	for(int i=0;i<n;i++){
		visited[i] = 0;
	}

	for(int i=0; i<n; i++){
		if(!visited[i]){
			printBFS(mat, n, i, visited);
		}
	}
	cout<<endl;

	delete [] visited;
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

	/*   input ==>  7 8
		0 1 0 6 1 6 1 3 6 3 2 5 2 4 4 5  */
	printDFS_DC(mat, n);
	printBFS_DC(mat,n);
	
	//free memory
	for(int i=0;i<n;i++){
		delete mat[i];
	}
	delete [] mat;
}