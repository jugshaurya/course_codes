//check whether tree is BST
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

class mytuple{
public:
    bool is_bst;
    int min;
    int max;
};
// we are starting building our results from bottom so bottom up
mytuple is_BST(BSTnode* root){
    mytuple obj;
    if(root->left == NULL || root->right==NULL){
        obj.is_bst = true;
        obj.max = obj.min = root->data;
        return obj;
    }

    mytuple rightans ;
    if(root->left == NULL){
        rightans = is_BST(root->right);
        obj.is_bst= true;
        obj.min = root->data;
        obj.max = rightans.max;
        return obj;
    }

    mytuple leftans;
    if(root->right == NULL){
        leftans = is_BST(root->left);
        obj.is_bst= true;
        obj.min = leftans.min;
        obj.max = root->data;
        return obj;
    }
    
    leftans = is_BST(root->left);
    rightans = is_BST(root->right);
    obj.is_bst = leftans.is_bst && rightans.is_bst &&(root->data >= leftans.max  && root->data < rightans.min);
    obj.min = leftans.min;
    obj.max = rightans.max; 
    return obj;
}

// Top-down
bool is_BST_TD(BSTnode* root, int minVal, int maxVal){

    if(root==NULL){
        return true;
    }

    return (root->data >=minVal && root->data <= maxVal &&
            is_BST_TD(root->left, minVal, root->data) &&
            is_BST_TD(root->right, root->data ,maxVal));
}


int main(){
    BSTnode* root = NULL;
    // 8 5 92 34 3  7 8 4 3 -1  -->INPUT.
    cin>>root; // takeInputInBST(root);
    cout<<root;
    mytuple t = is_BST(root);
    cout<<boolalpha<<t.is_bst<<endl;
    cout<<boolalpha<<is_BST_TD(root, INT_MIN, INT_MAX);
}
