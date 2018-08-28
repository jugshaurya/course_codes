#include<iostream>
using namespace std;

template<class T>
class genericTreeNode{
public:
	T data;
	int numberofchildren;
	genericTreeNode** childrenArr; 
    
	genericTreeNode(T data, int children){
		this->data = data;
		numberofchildren = children;
		childrenArr = new genericTreeNode*[numberofchildren]{};
	}
};

int main(){

}