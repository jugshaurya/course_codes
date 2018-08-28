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

void levelOrderPrintIter(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
    q.push(NULL); 
	while(!q.empty()) {
		TreeNode* node = q.front();
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

void mirror(TreeNode* root){

	if(root==NULL){
		return; 
	}

	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);

}

int main(){

	TreeNode* root = NULL;
    bulidTree(root);
    // 2 5 20 -1 -1 4 10 -1 -1 -1 100 18 -1 50 -1 -1 15 -1 -1 --> INPUT
    levelOrderPrintIter(root);
    cout<<"After looking into  Mirror "<<endl;
    mirror(root);
	levelOrderPrintIter(root);
}












