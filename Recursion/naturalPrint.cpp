// printing all natural numbers till n :
// A) In ascending order
// B) In descending order

#include <iostream>
using namespace std;

void naturalPrintAsc(int num){
	if(num==0){
		return ;
	}
	naturalPrintAsc(num-1);
	cout<<num<<" ";
}

void naturalPrintDesc(int num){
	if(num==0){
		return ;
	}
	cout<<num<<" ";
	naturalPrintDesc(num-1);
}

int main(){
	cout<<"Ascending: "<<endl;
	naturalPrintAsc(10);
	cout<<endl;
	cout<<"Descending: "<<endl;
	naturalPrintDesc(10);
	cout<<endl;
	return 0;
}