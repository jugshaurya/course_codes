#include<iostream>
#include<queue>
using namespace std;

//same as BSTnode
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

//functions used
void insertInBST(BSTnode* &, int);
void takeInputInBST(BSTnode* &);
// BSTnode* insertInBSTVersion2(BSTnode*, int);
void preorderPrint(BSTnode* );
void postorderPrint(BSTnode* );
void inorderPrint(BSTnode* );
void levelOrderPrintIter(BSTnode*);
int heightOfTree(BSTnode* );
void insertInBST(BSTnode*&, int );
bool searchInBST(BSTnode* ,int);
BSTnode* deletionInBST(BSTnode* ,int);


//insertion in BST

// BSTnode* insertInBSTVersion2(BSTnode* root, int data){
//  if(root == NULL){
//      root = new BSTnode(data);
//      return root;
//  }

//  if(data <= root->data ){
//      root->left = insertInBSTVersion2(root->left, data);
//  }else{
//      root->right = insertInBSTVersion2(root->right, data);
//  }
//     return root;
// }

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

//  search in BST
//O(height) 
bool searchInBST(BSTnode* root, int key){
    if(root==NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(key < root->data){
        return searchInBST(root->left, key);
    }

    
    if(key > root->data){
        return searchInBST(root->right, key);
    }
}


//deletion In BST

BSTnode* minimumNode(BSTnode* root){

    if(root->left == NULL){
        return root;
    }

    if(root->right==NULL && root->left==NULL){
        return root;
    }

    return minimumNode(root->left);
}

BSTnode* deletionInBST(BSTnode* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        //three cases
        
        // 1. leave node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 2. have a single child...
        if(root->left == NULL || root->right == NULL) {
            if(root->left == NULL){
                BSTnode* temp = root->right;
                delete root;
                return temp;
            }
            if(root->right == NULL){
                BSTnode* temp = root->left;
                delete root;
                return temp;
            }
        }

        //3. have both children
        // finding minimum in right subtree
        BSTnode* temp = minimumNode(root->right);
        swap(root->data, temp->data);
        root->right =  deletionInBST(root->right, temp->data);
        return root;
    }

    if(key < root->data){
        root->left = deletionInBST(root->left, key);
        return root;
    }
    root->right = deletionInBST(root->right, key);
    return root;
}

//height of tree
int heightOfTree(BSTnode* root){
    if(root == NULL){
        return 0;
    }

    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}

//printing
void preorderPrint(BSTnode* root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void inorderPrint(BSTnode* root){
    if(root==NULL){
        return ;
    }

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

void postorderPrint(BSTnode* root){
    if(root==NULL){
        return ;
    }

    postorderPrint(root->left);
    postorderPrint(root->right);
    cout<<root->data<<" ";
}

void levelOrderPrintIter(BSTnode* root){
    queue<BSTnode*> q;
    q.push(root);
    q.push(NULL); 
    while(!q.empty()) {
        BSTnode* node = q.front();
        q.pop();
        if(node == NULL && !q.empty()){
            cout<<endl;
            q.push(NULL);
            continue;
        }

        if(node == NULL){
            cout<<endl;
            continue;
        }

        cout << node->data << " ";
        if( node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }

    cout<<endl;
}

//operator overloading
ostream& operator<<(ostream& os, BSTnode* root){
    levelOrderPrintIter(root);
    return os;
}

istream& operator>>(istream& is, BSTnode*& root){
    takeInputInBST(root);
    return is;
}

int main(){

    BSTnode* root = NULL;
    // 8 5 92 34 3  7 8 4 3 -1  -->INPUT.
    cin>>root; // takeInputInBST(root);

    // int data;
    // cin>>data;
    // while(data!=-1){
    //     root = insertInBSTVersion2(root, data);        
    //     cin>>data;
    // }
    cout<<root;
    root = deletionInBST(root, 8);
    cout<< root;
    root = deletionInBST(root, 5);
    cout<< root;
    root = deletionInBST(root, 34);    
    cout<<root;
}





















