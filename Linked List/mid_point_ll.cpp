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
    int length();
public:
    LinkedList(){
        head = NULL;
    }
    void addToHead(int data);
    void takeInput();
	void print();
    int midpoint();
    int midpoint_runnerTechnique();
    int kthNodeFromEnd(int k);
};

int LinkedList::length(){
    Node* temp = head; 
    int count = 0 ;
    while(temp != NULL){
        temp =temp->next;
        count++;
    }

    return count;
}

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

int LinkedList::midpoint(){
    //calculate the length and then return length/2 th element
    Node* temp = head;
    int len = length();
    int jump = len/2 -1;
    while(jump){
        temp = temp->next;
        jump--;
    }
    if(len&1){
        return temp->next->data;    
    }else{
        return temp->data;
    }
    

    return temp->data;
}

int LinkedList::midpoint_runnerTechnique(){
    
    int len = length();
    Node* fast = head;
    Node* slow = head;
    if(!(len&1)){
        fast = fast->next;
    }

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;
}


int LinkedList::kthNodeFromEnd(int k){

	Node* fast =head;
	while(k-- && fast!=NULL){
		fast = fast->next;
	}

	Node* slow = head;
	while(fast!=NULL){
		fast = fast->next;
		slow = slow->next;
	}

	return slow->data;
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
    cin>>ll;
    cout<<ll;
    cout<<ll->midpoint()<<endl;
    cout<<ll->midpoint_runnerTechnique()<<endl;
    cout<<ll->kthNodeFromEnd(3)<<endl;
    cout<<ll->kthNodeFromEnd(9)<<endl;

}




