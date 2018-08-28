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

	/*   input  =>      7 8
		 0 1 0 2 1 3 1 4 2 6 3 5 4 5 5 6  */

	int* visited = new int[n];
	for(int i=0;i<n;i++){
		visited[i] = 0;
	}
	printDFS(mat, n, 0, visited );
    cout<<endl;

	for(int i=0;i<n;i++){
		visited[i] = 0;
	}
	printBFS(mat,n ,0,visited);
	
	//free memory
	for(int i=0;i<n;i++){
		delete mat[i];
	}

	delete [] mat;
	delete [] visited;
}