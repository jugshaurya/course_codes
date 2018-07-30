//push(), pop(), top(), empty(),  a.swap(b), swap(a,b).size(). 
#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s){
	cout<<s.size()<<endl;
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}

int main(){
	
	stack<int> s1;
	for(int i=0;i<10;i++){
		s1.push(i);
	}
	cout<<"first stack"<<endl;
	print(s1);

	stack<int> s2;
	for(int i=11;i<30;i++){
		s2.push(i);
	}
	cout<<"Second stack"<<endl;
	print(s2);

	//two type of swap
	cout<<"after swapping"<<endl;
	swap(s1,s2); 
	cout<<"first stack"<<endl;
	print(s1);
	cout<<"Second stack"<<endl;
	print(s2);

	cout<<"Again swapping"<<endl;
	s1.swap(s2); 
	cout<<"first stack"<<endl;
	print(s1);
	cout<<"Second stack"<<endl;
	print(s2);

}
