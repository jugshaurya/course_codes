#include<iostream>
using namespace std;

class polynomial{
	int* arr;
public:
	int size ;
	polynomial(int d = 4){
		arr = new int[d];
		size =d;
	}

	void inputPolynomial(){
		for(int i = 0; i<size; i++){
			cin>>arr[i];
		}
	}

	void getPolynomial(){
		for(int i = 0; i<size; i++){
			cout<<arr[i]<<"X^"<<i<<" ";
		}	
	}

	void addPolynomial(polynomial obj){
		int objsize = obj.size;
		for(int i=0;i<min(size, objsize));
	}
};