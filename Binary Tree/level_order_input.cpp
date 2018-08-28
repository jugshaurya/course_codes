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

void takeInputLevelWise(TreeNode*& root){
	queue<TreeNode*> q;
	int data;
	cin>>data;
	root = new TreeNode(data);
	q.push(root);
	while(!q.empty()){
		TreeNode* front = q.front();
		q.pop();
		
		cout<<"Enter the left-child of "<<front->data<<" ";
		cin>>data;
		if(data != -1){
			front->left = new TreeNode(data);
			q.push(front->left);
		}
		cout<<endl;
		
		cout<<"Enter the right-child of "<<front->data<<" ";
		cin>>data;
		if(data != -1){
			front->right = new TreeNode(data);
			q.push(front->right);
		}

		cout<<endl;
	}
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
    takeInputLevelWise(root);
    levelOrderPrintIter(root);
}
















