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


void removeLoop(Node *,Node *);
bool detectAndRemoveLoop(Node *head){
    Node *slow_p = head, *fast_p = head;
    while (slow_p && fast_p && fast_p->next){
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if (slow_p == fast_p) {
            removeLoop(slow_p, head);
            return true;
        }
    }

    /* Return false to indicate that there is no loop*/
    return false;
}

void removeLoop(Node *loop_node, Node *head){
    Node *ptr1 = head;
    Node *ptr2 = loop_node;

    while (ptr2->next != ptr1){
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }

    ptr2->next = NULL;
}

void print(Node* head){   
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}


int main(){
    Node *head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next = new Node(12);
    head->next->next->next->next->next->next->next = new Node(13);
    head->next->next->next->next->next->next->next->next = new Node(14);
    head->next->next->next->next->next->next->next->next->next = new Node(16);

    /* Create a loop for testing */
    head->next->next->next->next->next->next->next->next->next->next =
                                     head->next->next->next->next->next->next->next->next->next;
    if(detectAndRemoveLoop(head)){
        printf("Linked List after removing loop\n");
        print(head);
    }else{
        cout<<"Loop Not Found!";
    }
    return 0;
}










