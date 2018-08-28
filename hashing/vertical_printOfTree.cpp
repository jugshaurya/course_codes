#include<iostream>
#include<queue>
#include<map>
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

map<int ,vector<int> > mymap;
void verticalPrint(TreeNode* root,int d){
    if(root==NULL){
        return ;
    }

    mymap[d].push_back(root->data);
    verticalPrint(root->left , d-1);
    verticalPrint(root->right, d+1);
}

int main(){
    TreeNode* root = NULL;
    bulidTree(root);
    levelOrderPrintIter(root);
    verticalPrint(root,0);
	// 1 2 4 -1 -1 5 -1 8 -1 -1 3 6 -1 -1 7 -1 9 -1 -1  -->INPUT
    for(auto p: mymap){
        vector<int> v = p.second;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}