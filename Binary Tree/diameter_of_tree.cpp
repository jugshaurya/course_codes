//diameter of circle is maximum diatance b.w two points....
// similarly in tree

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
   
int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

//O(n^2)-->Top Down( O(nlogn) in case of balanced tree  && O(n*n) in case of skew tree )
int diameter(TreeNode* root){

	if(root == NULL){
		return 0; 
	}

	int option1 = height(root->left)  + height(root->right); //diameter passes through center->counting edges thats why di
	int option2 = diameter(root->left); //diameter lies in left part
	int option3 = diameter(root->right); //diameter lies in left part

	return max(option3, max(option2, option1));
}

class heightAndDiameter{
public: 
	int height;
	int diameter;
};

//Also Top Down--> but O(n) as we going on every node
heightAndDiameter fast_diameter(TreeNode* root){
	heightAndDiameter obj;
	if(root == NULL){
		obj.height = 0 ;
		obj.diameter = 0;
		return obj; 
	}

	heightAndDiameter left = fast_diameter(root->left);
	heightAndDiameter right = fast_diameter(root->right);
	obj.height =  max(left.height ,right.height) + 1;
	int option1 = left.height + right.height;
	int option2 = left.diameter;
	int option3 = right.diameter;
	obj.diameter = max(option3,max(option2,option1));
	return obj;
}


int main(){
    TreeNode* root = NULL;
    bulidTree(root);
    // 8 10 1 7 8 9 -1 -1 -1 -1  -1 6 9 10 11 -1 -1 -1 -1  -1 3 -1 -1--> INPUT(diameter lies in left subtree).
    cout<<diameter(root)<<endl;
    cout<<fast_diameter(root).diameter<<endl;
}