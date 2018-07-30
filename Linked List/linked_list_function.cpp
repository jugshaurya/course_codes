#include <iostream>
using namespace std;

void insertAtHead(node*&head,int data);
int length(node*head);
void insertAtTail(node*&head,int data);
void insertInMiddle(node*&head,int data,int p);
bool searchRecursive(node*head,int key);
bool searchIterative(node*head,int key);
void print(node*head);
void deleteAtHead(node*&head);
void deleteInTheMiddle(node* &head,int pos);
void buildList(node*&head);
node* midPoint(node*head);

class node{
public:
    int data;
    node* next;
    
    //Constructor
    node(int d){
        data = d;
        next = NULL;
    }
};

//Passing a pointer variable by reference 
void insertAtHead(node*&head,int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}

int length(node*head){
    
    int len=0;
    while(head!=NULL){
        head = head->next;
        len += 1;
    }
    return len;
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

void insertInMiddle(node*&head,int data,int p){
    
    if(head==NULL||p==0){
        insertAtHead(head,data);
    }   
    else if(p>length(head)){
        insertAtTail(head,data);
    }
    else{
        //Insert in the middle 
        //Take p-1 jumps
        int jump=1;
        node*temp = head;
        while(jump<=p-1){
            temp = temp->next;
            jump += 1;
        }
        
        node*n = new node(data);
        n->next = temp->next;
        temp->next = n;
        
    }
}

bool searchRecursive(node*head,int key){
    if(head==NULL){
        return false;
    }
    //Rec Case 
    if(head->data ==key){
        return true;
    }
    else{
        return searchRecursive(head->next,key);
    }
}

bool searchIterative(node*head,int key){
    
    while(head!=NULL){
        if(head->data==key){
            return true;
        }
        head = head->next;
    }
    return false;
}

void print(node*head){
    //node*temp = head;
    
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

void deleteAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteInTheMiddle(node* &head,int pos){
    if(head == NULL || pos == 0){
        return;
    }

    if(pos == 1){
        deleteFromHead(head);
        return; 
    }

    node* temp = head;
    while(((--pos)-1) && temp->next->next!=NULL){
        temp = temp->next;
    }

    node* to_be_deleted = temp->next;
    temp->next = to_be_deleted->next;
    delete to_be_deleted;
}

node* midPoint(node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    node*slow = head;
    node*fast = head->next;
    
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
    
}

void buildList(node*&head){
    
    int data;
    cin>>data;
    
    while(data!=-1){
        insertAtTail(head,data);
        cin>>data;
    }
}

istream& operator>>(istream& is, node*& head){
    buildList(head);
    return is;
}

ostream& operator>>(ostream& os, node* head){
    print(head);
    return os;
}


int main() {
    node*head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtTail(head,6);
    
    insertInMiddle(head,2,3);
    print(head);
    
    if(searchRecursive(head,4)){
        cout<<"Element is present !"<<endl;
    }
    else{
        cout<<"Not present !";
    }
    
    if(searchIterative(head,14)){
        cout<<"Element is present !";
    }
    else{
        cout<<"Not present !";
    }
    
    deleteAtHead(head);
    deleteAtTail(head);
    deleteInTheMiddle(head, 2);
    print(head);
    
    return 0;
}
