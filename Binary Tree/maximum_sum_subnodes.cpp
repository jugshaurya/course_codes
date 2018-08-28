//find a subset of nodes with maximim sum such that
// if a node is included to subset then u can't include its children and parents into subset.

#include<iostream>
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

void preorderPrint(TreeNode* root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

class mypair{
	public:
		int includeSum;
		int excludeSum;
};

mypair maximumSum(TreeNode* root){
	mypair obj;
	if(root == NULL){
		obj.includeSum = 0;
		obj.excludeSum = 0;
		return obj;
	}

	mypair leftMaxSum = maximumSum(root->left);
	mypair rightMaxSum = maximumSum(root->right);

	obj.includeSum = root->data + leftMaxSum.excludeSum + rightMaxSum.excludeSum ; 
	obj.excludeSum = max(leftMaxSum.includeSum, leftMaxSum.excludeSum) 
					+ max(rightMaxSum.includeSum, rightMaxSum.excludeSum);

	return obj;
}

int main(){

	TreeNode* root = NULL;
    bulidTree(root);
    // 2 5 20 -1 -1 4 10 -1 -1 -1 100 18 -1 50 -1 -1 15 -1 -1 --> INPUT
    preorderPrint(root);
    cout<<endl;
    mypair p = maximumSum(root);
    cout<< "Max SUM IS "<< max(p.includeSum, p.excludeSum);  
}
















