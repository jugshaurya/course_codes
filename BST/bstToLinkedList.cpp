//convert bst to linked list
#include <iostream>
#include<climits>
using namespace std;

class BSTnode{
public:
    int data;
    BSTnode* left;
    BSTnode* right;

    BSTnode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void insertInBST(BSTnode* & root, int data){
    
    if(root == NULL){
        root = new BSTnode(data);
        return ;
    }

    if(data <= root->data ){
        insertInBST(root->left, data);
    }else{
        insertInBST(root->right, data);
    }
}

void takeInputInBST(BSTnode*& root){
    int data;
    cin>>data;
    while(data!=-1){
        insertInBST(root, data);        
        cin>>data;
    }
}

void preorderPrint(BSTnode* root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

//operator overloading
ostream& operator<<(ostream& os, BSTnode* root){
    preorderPrint(root);
    return os;
}

istream& operator>>(istream& is, BSTnode*& root){
    takeInputInBST(root);
    return is;
}

class mypair{
public:
    BSTnode* head;
    BSTnode* tail;
};

mypair BSTToLinkedList(BSTnode* root){
    mypair ll;
    if(root ==  NULL){
        ll.head = NULL;
        ll.tail = NULL;
        return ll;
    }

    if(root->left==NULL && root->right==NULL){
        ll.head = ll.tail = root;
        return ll;
    }

    mypair leftll;
    mypair rightll;
    if(root->right == NULL){
        leftll = BSTToLinkedList(root->left);
        ll.head =  leftll.head;
        leftll.tail->right = root;
        ll.tail = root;
        return ll;
    }

    if(root->left == NULL){
        rightll = BSTToLinkedList(root->right);
        ll.head = root;
        root->right = rightll.head;
        ll.tail = rightll.tail;
        return ll;
    }

    leftll = BSTToLinkedList(root->left);
    rightll = BSTToLinkedList(root->right);    
    leftll.tail->right = root;
    root->right = rightll.head;
    ll.head = leftll.head;
    ll.tail = rightll.tail;
    return ll;
}

int main(){
    BSTnode* root = NULL;
    // 8 5 92 34 3  7 8 4 3 -1  -->INPUT.
    cin>>root; // takeInputInBST(root);
    cout<<root;
    cout<<endl;
    mypair p = BSTToLinkedList(root);
    BSTnode* temp = p.head;
    while(temp != NULL){
        cout<<temp->data<<"-->";
        temp = temp->right;
    }
    cout<<"END";
}