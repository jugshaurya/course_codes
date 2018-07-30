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

int length(Node* head){
    Node* temp = head; 
    int count = 0 ;
    while(temp != NULL){
        temp =temp->next;
        count++;
    }

    return count;
}

Node* merge(Node* head1, Node* head2){

    if(head1==NULL){
        return head2;
    }

    if(head2==NULL){
        return head1;
    }


    if(head1->data < head2->data){
        head1->next = merge(head1->next, head2);
        return head1;
    }else{
        head2->next = merge(head1, head2->next);
        return head2;
    }
}

Node* midpoint_runnerTechnique(Node* head){
    
    int len = length(head);
    Node* fast = head;
    Node* slow = head;
    if(!(len&1)){
        fast = fast->next;
    }

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

void merge_sort(Node*& head){
    if(head->next == NULL || head==NULL){
        return ;
    }

    Node* mid = midpoint_runnerTechnique(head);
    Node* head2 = mid->next;
    mid->next = NULL;

    merge_sort(head);
    merge_sort(head2);
    head = merge(head,head2);
}


void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" "<<flush;
        temp = temp->next;
    }

    cout<<endl;
}

void addToHead(Node*& head , int data){
    Node* newnode = new Node(data);
    
    newnode->next = head;
    head = newnode;
}

void takeInput(Node*& head){

    int data;
    cin>>data;
 
    while(data != -1){
        addToHead(head,data);
        cin>>data;
    }
}

//operator overloading
istream& operator>>(istream& is, Node*& head){
    takeInput(head);
    return is;
}

ostream& operator<<(ostream& os, Node* head){
    print(head);
    return os;
}


//main function
int main(){
    Node* head = NULL;
    cin>>head;
    cout<<head;
    merge_sort(head);
    cout<<head;
}




