
//inplicit stack --> recursion
//explicict stack -->  stack class 
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

void insertAtBottom(stack<int>& s, int el){
	if(s.empty()){
		s.push(el);
		return;
	}

	int topElement = s.top();
	s.pop();
	insertAtBottom(s,el);
	s.push(topElement);
}

void reverse_using2_implicit_stack(stack<int> &s){
	if(s.empty()){
		return;
	}

	int topElement = s.top();
	s.pop();
	reverse_using2_implicit_stack(s);
	insertAtBottom(s,topElement);
}

void reverse_using2_explicit_stack(stack<int> &s){

	stack<int> s1, s2;
	//from s to s1
	while(!s.empty()){
		s1.push(s.top());
		s.pop();
	}

	//s1 to s2
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}

	//s2 to s
	while(!s2.empty()){
		s.push(s2.top());
		s2.pop();
	}
}

void insertAtBottom2(stack<int>& s, int el){
	stack<int> temp ;	
	while(s.empty()==false){
		temp.push(s.top());
        s.pop();
	}	
	s.push(el);

	while(temp.empty()==false){
		s.push(temp.top());
		temp.pop();
	}
}
void reverse_using1_implicit1_explicit_stack(stack<int> & s){
	if(s.empty()){
		return;
	}

	int topElement = s.top();
	s.pop();
	reverse_using1_implicit1_explicit_stack(s);
	insertAtBottom2(s,topElement);
}

int main(){

	stack<int> s;
	for(int i=0;i<5;i++){
		s.push(i);
	}	
	print(s);

	reverse_using2_explicit_stack(s);
	print(s);
	reverse_using2_implicit_stack(s);
	print(s);
	reverse_using1_implicit1_explicit_stack(s);
	print(s);
}
