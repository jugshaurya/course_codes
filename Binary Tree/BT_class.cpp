#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

//not using class approach !
// class BinaryTree{
// };

//function used
void preorderPrint(TreeNode* root);
void postorderPrint(TreeNode* root);
void inorderPrint(TreeNode* root);
void levelOrderPrintIter(TreeNode* root);
int heightOfTree(TreeNode* root);
void printLevel(TreeNode* root , int level);
void levelOrderPrintRec(TreeNode* root);
int numberOfNodes(TreeNode* root);
int sumOfAllNodes(TreeNode* root);

void bulidTree(TreeNode* &root){
	//taking input in  preorder way
	int data;
    cin>>data;
	if(data == -1){
		return ;
	}

	root = new TreeNode(data);
	bulidTree(root->left);
	bulidTree(root->right);
}

//buildTree version B
// TreeNode* buildTreeB(){
//     int data;
//     cin>>data;
//     if(data == -1){
//         return NULL;
//     }

//     TreeNode* root = new TreeNode(data);
//     root->left = buildTreeB();
//     root->right = buildTreeB();
//     return root;
// }

void preorderPrint(TreeNode* root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void postorderPrint(TreeNode* root){
    if(root==NULL){
        return ;
    }

    postorderPrint(root->left);
    postorderPrint(root->right);
    cout<<root->data<<" ";
}

void inorderPrint(TreeNode* root){
    if(root==NULL){
        return ;
    }

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

void levelOrderPrintIter(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode* node = q.front();
		cout<<node->data<<" ";
		q.pop();
        if( node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
	}
	cout<<endl;
}

int heightOfTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}

void printLevel(TreeNode* root , int level){
    if(root == NULL){
        return ;    
    }
    if(level == 0 ){
        cout<<root->data<<" ";
        return ;
    }

    printLevel(root->left, level-1);
    printLevel(root->right, level-1);
}

void levelOrderPrintRec(TreeNode* root){
    int n = heightOfTree(root);
	for(int i = 0; i<n; i++) {
        printLevel(root, i);
    }

    cout<<endl;
}

int numberOfNodes(TreeNode* root){

    if(root==NULL){
        return 0;
    }

    return numberOfNodes(root->left) + numberOfNodes(root->right) + 1 ;
}

int sumOfAllNodes(TreeNode* root){

    if(root==NULL){
        return 0;
    }

    return root->data + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);

}

int main(){

	TreeNode* root = NULL;
    bulidTree(root);
    // root = buildTreeB(); --> version B
    // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 --> INPUT
    preorderPrint(root);
    cout<<endl;
    inorderPrint(root);
    cout<<endl;
    postorderPrint(root);
    cout<<endl;
    levelOrderPrintIter(root);
    levelOrderPrintRec(root);
    cout<<numberOfNodes(root)<<endl;
    cout<<sumOfAllNodes(root)<<endl;
}