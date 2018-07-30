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
    bool searchRec(Node* head , int key);
public:
    LinkedList(){
            head = NULL;
        }

	void addToHead(int data);
	void addToTail(int data);
	void addAtMiddle(int data, int pos);
	void deleteFromHead();
	void deleteFromTail();
	void deleteFromMiddle(int pos);
	bool searchIter(int key);
	bool searchRecursive(int key){
        return searchRec(head, key);
    }
    void takeInput();
	void print();
	
	// ~LinkedList(){
	// 	delete head;
	// }
};

void LinkedList::addToHead(int data){
	Node* newnode = new Node(data);
	newnode->next = head;
	head = newnode;
}

void LinkedList::addToTail(int data){
	if(head == NULL){
		addToHead(data);
		return;
	}

	Node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = new Node(data);
}

void LinkedList::addAtMiddle(int data, int pos){
	if(head == NULL || pos == 0 ){
		addToHead(data);
		return;
	}

	Node* temp = head;
	while(--pos && temp->next!=NULL){
		temp = temp->next;
	}
	
	Node* newnode = new Node(data);
	newnode->next = temp->next;
	temp->next = newnode;
}

void LinkedList::deleteFromHead(){
	if(head==NULL){
		return;
	}

	Node* temp = head;
	head = head->next;
	delete temp;
}

void LinkedList::deleteFromTail(){

	if(head==NULL){
		return;
	}
	
	Node* tailprev = head ;
	while(tailprev->next->next != NULL){
		tailprev = tailprev->next;
	}

	delete tailprev->next;
	tailprev->next = NULL;
}

void LinkedList::deleteFromMiddle(int pos){

	if(head == NULL || pos == 0){
		return;
	}

	if(pos == 1){
		deleteFromHead();
		return; 
	}

	Node* temp = head;
	while(((--pos)-1) && temp->next->next!=NULL){
		temp = temp->next;
	}

	Node* to_be_deleted = temp->next;
	temp->next = to_be_deleted->next;
	delete to_be_deleted;
}

void LinkedList::print(){
		Node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
        cout<<endl;
}

bool LinkedList::searchRec(Node* temp, int key){

	if(temp == NULL){
		return false;
	}

	if(temp->data == key){
		return true;
	}else{
		return searchRec(temp->next, key);
	}
}

bool LinkedList::searchIter(int key){
	Node* temp = head;
	while(temp!=NULL){
		if(temp->data == key){
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void LinkedList::takeInput(){

    int data;
    cin>>data;
 
    while(data!=-1){
        addToTail(data);
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


//main function
int main(){
	LinkedList* ll  = new LinkedList;
	ll->addToHead(4);ll->addToHead(5);ll->addToHead(6);
	ll->addToTail(4);ll->addToTail(5);ll->addToTail(6);
    ll->print();

	ll->addAtMiddle(8,0);ll->addAtMiddle(8,2);ll->addAtMiddle(9,3);
	ll->print();

    cout<<boolalpha<<ll->searchIter(5)<<endl;
    cout<<boolalpha<<ll->searchIter(65)<<endl;
    cout<<boolalpha<<ll->searchRecursive(5)<<endl;
    cout<<boolalpha<<ll->searchRecursive(65)<<endl;

    ll->deleteFromHead(); ll->print();
    ll->deleteFromTail(); ll->print();
    ll->deleteFromMiddle(0) ; ll->print();
    ll->deleteFromMiddle(1); ll->print();
    ll->deleteFromMiddle(2);  
    ll->print();
    // cin>>ll;
    // cout<<ll;

}