/*
    Implement k Reverse (int k) i.e. you have to reverse first K elements then reverse next K elements and 
    join the linked list and so on. 3 → 4 → 5 → 2 → 6 → 1 → 9 for k reverse(3) becomes 
    5 → 4 → 3 → 1 → 6 → 2 → 9 → 1. 
     If k is greater than the size of rest linked list then reverse the rest part. 
    Ex. For linked list 5 → 4 → 3 → 1 and k =5. Output should be 1 → 3 → 4 → 5.
*/

#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(node*&head,int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}

void insertAtTail(node*&head,int data){
    
    if(head==NULL){
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void print(node*head){
    //node*temp = head;
    
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

node* reverseRec(node*head){
    //Base Case 
    if(head->next==NULL||head==NULL){
        return head;
    }
    //Rec Case
    node*smallHead = reverseRec(head->next);
    node*C = head;
    C->next->next = C;
    C->next = NULL;
    return smallHead;
    
}

void buildList(node*& head, int n){
    int data;
    while(n!=0){
        cin>> data;
        insertAtTail(head, data);
        n--;
    }
}

node* reversek(node* head , int k){

    if(head == NULL){
        return NULL;
    }

    int size = k-1;
    node* head1 = head;
    while( size && head1->next!=NULL ) {
        head1 = head1->next;
        size--;
    }

    node* nextchain = head1->next;
    head1->next = NULL;
    head = reverseRec(head);

    // print(head);

    node* head2 =  reversek(nextchain,k);
    head1 = head;     //may be automatically done--> fir bhi!!
    while(head1->next != NULL){
        head1 = head1->next;
    }

    head1->next  = head2;
    return head;
}

void deleteList(node* head){

	node* temp = head;
	while(head!=NULL){
		head = head->next;
		delete temp;
		temp = head;
	}
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        node* head = NULL;
        buildList(head,n);
        // print(head);
        int k;
        cin>>k;

        head = reversek(head,k);
        print(head);

        deleteList(head);
    }

}