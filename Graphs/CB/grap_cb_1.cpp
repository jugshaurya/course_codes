/* Adjacency list using hashmap */
#include<iostream>
#include<map>
#include<string>
#include<list>
using namespace std;

template<typename T>
class graph{
	int V;
	map<T, list<T> > l;

public:
	graph(int v){
		V = v;
	}

	void addEdges(T v1, T v2, bool bidir = true){
		l[v1].push_back(v2);
		if(bidir){
			l[v2].push_back(v1);
		} 
	}

    
	void printAdjacencyList() {
		typename map<T, list<T> >::iterator it = l.begin();
		for(; it != l.end(); it++){
			cout<<(*it).first<<"-->";
			for( T x : (*it).second){
				cout<<x<<",";
			}
			cout<<endl;
		}
	}
};

int main(){
/*  
	 input  =>      7 8
	 0 1 0 2 1 3 1 4 2 6 3 5 4 5 5 6 
 */
	
	graph<int> g(7);
	g.addEdges(0,1);
	g.addEdges(0,2);
	g.addEdges(1,3);
	g.addEdges(1,4);
	g.addEdges(2,6);
	g.addEdges(3,5);
	g.addEdges(4,5);
	g.addEdges(5,6);
	g.printAdjacencyList();
	

    graph<string> gs(6);
	gs.addEdges("Putin", "Trump", false);
	gs.addEdges("Putin", "Modi", false);
	gs.addEdges("Putin", "Pope", false);
	gs.addEdges("Trump", "Modi");
	gs.addEdges("Prabhu", "Modi", false);
	gs.addEdges("Modi", "Yogi");
	gs.addEdges("Yogi", "Prabhu", false);
    gs.printAdjacencyList();
}
