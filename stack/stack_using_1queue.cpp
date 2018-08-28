#include<iostream>
#include<queue>
using namespace std;

class stack{

	queue<int>* q;
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
	q = new queue<int>;
}

stack::~stack(){
	delete q;
}

void stack::push(int data){
	q->push(data);
}

void stack::pop(){
	if(!q->empty()){
		int size = q->size();
		while(size != 1){
			int top = q->front();
			q->pop();
			q->push(top);
			size--;
		}
		q->pop();
	}else{
		cout<<"stack is empty "<<endl;
		return;
	}
}

int stack::top() const{
    if(!q->empty()){
		int size = q->size();
		while(size != 1){
			int top = q->front();
			q->pop();
			q->push(top);
			size--;
		}
		int topElement = q->front();
		q->pop();
		q->push(topElement);
		return topElement; 
	}else{
		cout<<"stack is empty ";
		return -1;
	}
}

int stack::size() const{
	 return q->size();
}

bool stack::empty() const{
	return q->empty();
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









