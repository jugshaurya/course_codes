/* Adjacency list using array of linked list */
#include<iostream>
#include<list>
#include<queue> //for bfs
using namespace std;

class graph{
	int V;
	list<int>* l;
public:
	graph(int v){
		V = v;
		l = new list<int>[V]; 
	}

	void addEdges(int v1, int v2, bool bidir = true){
		l[v1].push_back(v2);
		if(bidir){
			l[v2].push_back(v1);
		} 
	}

	void bfs(int sv){
		queue<int> q;
		int* visited = new int[V];
		for(int i=0;i<V;i++){
			visited[i] = 0;
		}

		q.push(sv);
		visited[sv] = 1;
		while(!q.empty()){
			int topel = q.front();
			cout<<topel<<" ";
			q.pop();
			for(int li : l[topel]){
				if(!visited[li])
					q.push(li);
                    visited[li] =1;
			}
		}
		delete [] visited;
	}

	void dfs(int sv){
		int* visited = new int[V];
		for(int i=0;i<V;i++){
			visited[i] = 0;
		}

		dfsHelper(sv, visited);
		delete [] visited;
	}

	void dfsHelper(int sv, int* visited){
		visited[sv] = 1;
		cout<<sv<<" ";
		for(int el : l[sv]){
            if(!visited[el])
                dfsHelper(el, visited);
		}
	}

	void printAdjacencyList(){
		for(int i=0;i<V;i++){
			cout<<i<<"-->";
			for(int li : l[i]){
				cout<<li<<",";
			}
			cout<<endl;
		}
	}
};

int main(){

/*   input  =>      7 8
		 0 1 0 2 1 3 1 4 2 6 3 5 4 5 5 6  */
	graph g(7);
	g.addEdges(0,1);
	g.addEdges(0,2);
	g.addEdges(1,3);
	g.addEdges(1,4);
	g.addEdges(2,6);
	g.addEdges(3,5);
	g.addEdges(4,5);
	g.addEdges(5,6);
	cout<<"BFS"<<endl;
    g.bfs(0);
    cout<<endl;
	
	cout<<"DFS"<<endl;
    g.dfs(0);
}












