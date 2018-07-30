#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int d, Node* n = NULL){
		data = d;
		next = n;
	}
};

class LinkedList{
private:
	Node* head;
	Node* reverseRecHelper(Node*);
public:
    LinkedList(){
        head = NULL;
    }

    void reverseIter();
    void reverseRec(){
    	head = reverseRecHelper(head);
    }
    void addToHead(int data);
    void takeInput();
	void print();
};

void LinkedList::print(){
		Node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
        cout<<endl;
}

void LinkedList::addToHead(int data){
	Node* newnode = new Node(data);
	newnode->next = head;
	head = newnode;
}

void LinkedList::takeInput(){

    int data;
    cin>>data;
 
    while(data!=-1){
        addToHead(data);
        cin>>data;
    }
}

//oprerator overloading
istream& operator>>(istream& is, LinkedList* ll){
    ll->takeInput();
	return is;
}

ostream& operator<<(ostream& os, LinkedList* ll){
    ll->print();
	return os;
}

Node* LinkedList::reverseRecHelper(Node* temp){

    if(temp==NULL){
        return NULL;
    }
	if(temp->next == NULL){
		return temp;
	}

	Node* newhead = reverseRecHelper(temp->next);
    while(head->next != NULL){
		head = head->next;
	}

	head->next = temp;
	temp->next =NULL;
    return newhead;
}

void LinkedList::reverseIter(){
	
	Node* current = head;
	Node* prev = NULL;
	Node* coming_up = NULL;
	while(current!=NULL){
		coming_up = current->next;
		current->next = prev;
		prev=current;
		current = coming_up;
	}

	head = prev;
}


//main function
int main(){
	LinkedList* ll  = new LinkedList;
    cin>>ll;
    cout<<ll;
	ll->reverseRec();
    cout<<ll;
	ll->reverseIter();
    cout<<ll;
}
