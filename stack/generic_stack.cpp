//stack implemented using linked list
#include<iostream>
#include<string>
using namespace std;

class Person{
	string name;
	int age;

public:
	Person(){
		name = "NULL";
		age=-1;
	}

	Person(string n, int yr){
		name = n;
		age = yr;
	}

    string getname() const{
        return name;
    }

    int getage() const{
        return age;
    }
};

template<class T>
class stack{
	class Node{
	public:
		T data;
		Node* next;

		Node(T data){
			this->data = data;
			next = NULL;
		}
	};

	Node* head;
	int sze;
	void addTohead(T data){
		Node* newnode = new Node(data);
		newnode->next = head;
		head = newnode;
	}

public:
	stack();//constructor
	void push(T data);
	void pop();
	T top() const;
	int size() const;
	bool empty() const;
	~stack();
};

template<class T>
stack<T>::stack(){
	head = NULL;
	sze = 0;
}


template<class T>
stack<T>::~stack(){
	Node* temp = head;
	while(head!=NULL){
		temp = head;
		head = head->next;
		delete temp;
	}
}


template<class T>
void stack<T>::push(T data){
	addTohead(data);
	sze++;	
}


template<class T>
void stack<T>::pop(){
	if(head == NULL){
		return;
	}

	Node* temp = head->next;
	delete head;
	head = temp;
	sze--;
}


template<class T>
T stack<T>::top() const{
    if(head == NULL){
        return Person();
    }
    
	return head->data;
}


template<class T>
int stack<T>::size() const{
	return sze;
}


template<class T>
bool stack<T>::empty() const{
	return head == NULL;
}

ostream& operator<<(ostream& os, Person b){
    cout<<b.getname()<<" "<<b.getage();
    return os;
}

int main(){
	stack<Person> s;
	Person family[] = {
		{"priyansh",19},
		{"shaurya",21},
		{"Tanmay",20},
		{"Kajal",17},
		{"MOM",46},
		{"DAD",47}
	};
	s.push(family[0]);
	s.push(family[1]);
	s.push(family[2]);
	s.push(family[3]);
	s.push(family[4]);
	s.push(family[5]);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.size()<<endl;
	cout<<s.empty()<<endl;
}
