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

void preorderPrint(TreeNode* root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int heightOfTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}


//  its complexity is high because once it is saying find isbalanced and find height and again calling height so it is 
//  calling height again and again...
// O(n square)
bool is_balanced(TreeNode* root){

    if(root == NULL){
        return true;
    }

    bool left = is_balanced(root->left);
    bool right = is_balanced(root->right);
    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    if(lh-rh== 0 || lh-rh == 1 || lh-rh == -1){
        return left && right ;
    }else{
        return false;
    }
}

class mypair{
public: 
    bool balanced;
    int height;
};


mypair is_balanced_fast(TreeNode* root){
    mypair obj;
    if(root == NULL){
        mypair.balanced = true;
        mypair.height = 0;
    }

    mypair leftans = is_balanced_fast(root->left);
    mypair rightans = is_balanced_fast(root->right);
    obj.height = max(leftans.height, rightans.height) + 1;
    int lh = leftans.height;
    int rh = rightans.height;
    if(lh-rh == 0 || lh-rh == 1 || lh-rh == -1){
        obj.balanced =  leftans.balanced && rightans.balanced ;
    }else{
        obj.balanced =  false;
    }

    return obj;
}

void levelOrderPrintIter(TreeNode* root){
    if(root==NULL){
        return ;
    }
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
    // 3 4 6 9 -1 -1 -1 -1 5 -1 -1 --> INPUT
    preorderPrint(root);
    // levelOrderPrintIter(root);
    cout<<endl;
    cout<<is_balanced(root);
}
