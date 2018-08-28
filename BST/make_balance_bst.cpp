// You are given a sorted data of n integers. You have to form a balanced Binary Search Tree and
 // then print preorder traversal of the tree.
// Sample Input:
// 7
// 1 2 3 4 5 6 7

// Sample Output:
// 4 2 1 3 6 5 7
#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
        
        node( int d ){
            data = d;
            left = NULL;
            right = NULL;
        }
};

void printPreOrder(node* root){
    if(root ==  NULL){
        return;
    }
    cout << root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

node* makeBalancedTree(int* arr, int n){

    if(n<=0){
        return NULL;
    }

    int mid = (n-1)/2;
    node* root = new node(arr[mid]);
    root->left = makeBalancedTree(arr,mid);
    root->right = makeBalancedTree(arr+mid+1,n-mid-1); 
    return root;
}

void makeBalanceAndPrint(int* arr, int n){
    //make balanced
    node* root = NULL;
    root = makeBalancedTree(arr,n);
    printPreOrder(root);
}

int main() {

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        makeBalanceAndPrint(arr,n);
        cout<<endl;
    }
}
