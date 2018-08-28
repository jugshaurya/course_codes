#include<iostream>
#include<queue>
using namespace std;

class stack{
	queue<int> *q1; //elements are always pushed into q1
	queue<int> *q2;
	public:
	stack(); //constructor
	void push(int data);
	void pop();
	int top() const;
	int size() const;
	bool empty() const;
	~stack();
};

stack::stack(){
	q1 = new queue<int>;
	q2 = new queue<int>;
}

stack::~stack(){
	delete q1;
	delete q2;
}

void stack::push(int data){
	q1->push(data);
}

void stack::pop(){
	if(!q1->empty()){
		while(q1->size()!=1){
			q2->push(q1->front());
			q1->pop();
		}
		//remove the top element
		q1->pop();
		swap(q2,q1);
	}else{
		cout<<"stack is empty"<<endl;
	}
}

int stack::top() const{
	if(!q1->empty()){
		while(q1->size()!=1){
			q2->push(q1->front());
			q1->pop();
		}
		//remove the top element
		return q1->front();
	}
	cout<<"stack is empty ";
	return -1;
}

int stack::size() const{
	return q1->size() + q2->size();
}

bool stack::empty() const{
	return q1->empty();
}

int main(){
	stack s;
	s.push(76);
	s.push(7);
	s.push(6);
	s.push(716);
	cout<<s.top()<<endl;
	s.pop();
    s.pop();
    s.pop();
    s.pop();
	cout<<s.top()<<endl;
	cout<<s.size()<<endl;
	cout<<s.empty()<<endl;

}









