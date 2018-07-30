//stack implemented using linked list
#include<iostream>
using namespace std;

class stack{
	class Node{
	public:
		int data;
		Node* next;

		Node(int data){
			this->data = data;
			next = NULL;
		}
	};

	Node* head;
	int sze;
	void addTohead(int data){
		Node* newnode = new Node(data);
		newnode->next = head;
		head = newnode;
	}

public:
	stack();//constructor
	void push(int data);
	void pop();
	int top() const;
	int size() const;
	bool empty() const;
	~stack();
};

stack::stack(){
	head = NULL;
	sze = 0;
}

stack::~stack(){
	Node* temp = head;
	while(head!=NULL){
		temp = head;
		head = head->next;
		delete temp;
	}
}

void stack::push(int data){
	addTohead(data);
	sze++;	
}

void stack::pop(){
	if(head == NULL){
		return;
	}

	Node* temp = head->next;
	delete head;
	head = temp;
	sze--;
}

int stack::top() const{
    if(head == NULL){
        return -1;
    }
    
	return head->data;
}

int stack::size() const{
	//run in O(1)
	return sze;
	//runs in O(length of stack)
	// Node* temp = head;
	// int count =0;
	// while(temp!=NULL){
	// 	count++;
	// 	temp = temp->next;
	// }

	// return count;
}

bool stack::empty() const{
	return head == NULL;
}

int main(){
	stack s;
	s.push(76);
	s.push(7);
	s.push(6);
	s.push(716);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.size()<<endl;
	cout<<s.empty()<<endl;
}