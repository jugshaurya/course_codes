//Queue implemented using linked list
#include<iostream>
using namespace std;

class queue{
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
	Node* tail;
	int sze;
public:
	queue();//constructor
	void push(int data);
	void pop();
	int front() const;
	int size() const;
	bool empty() const;
	~queue();
};

queue::queue(){
	head = tail = NULL;
	sze = 0;
}	

queue::~queue(){
	Node* temp = head;
	while(head!=NULL){
		temp = head;
		head = head->next;
		delete temp;
	}
}

// Insertion at tail
//deletion from head
void queue::push(int data){	

	Node* newnode = new Node(data);
	if(head==NULL){
		head = tail = newnode;
		sze++;
		return;
	}

	tail->next = newnode;
	tail =newnode;
	sze++;
}

void queue::pop(){
	if(head==NULL){
		return;
	}	

	if(head == tail){
		delete head;
		head = tail = NULL;
		sze--;
		return;
	}

	Node* temp =head;
	head = head->next;
	delete temp;
	sze--;
}

int queue::front() const{
    if(head==NULL){
        return -1;
    }
   return head->data;
}

int queue::size() const{
	return sze;
}

bool queue::empty() const{
	return head == NULL;
}

int main(){
	queue q;
	q.push(76);
	q.push(7);
	q.push(6);
	q.push(716);
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	cout<<q.size()<<endl;
	cout<<q.empty()<<endl;
}
