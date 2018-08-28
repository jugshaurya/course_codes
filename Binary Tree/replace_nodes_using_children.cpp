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

//replace every node with sum of its children and itself.
int replace_with_sum(TreeNode* root){

	if(root == NULL){
		return 0; 
	}

	int lsum = replace_with_sum(root->left);
	int rsum = replace_with_sum(root->right);
	root->data += lsum + rsum; 
	return root->data;
}

//replace every node with sum of its children only .
int replace_with_children_sum(TreeNode* root){

	if(root == NULL){
		return 0; 
	}

    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
	int lsum = replace_with_children_sum(root->left);
	int rsum = replace_with_children_sum(root->right);
    int temp = root->data;
	root->data = lsum + rsum; 
	return root->data + temp;
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

int main(){
    TreeNode* root = NULL;
    bulidTree(root);
    levelOrderPrintIter(root);
    replace_with_children_sum(root);
    levelOrderPrintIter(root);
}