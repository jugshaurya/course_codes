#include<bits/stdc++.h>
using namespace std;

/*
	Find the max xor pair from array
	ex-> 15,14,12,10,5,6
	ans -> 15(10,5).
*/

class trieNode{
public:
	trieNode* left; //indicating zero
	trieNode* right; //indicating one
	trieNode(){
		left = right = NULL;
	}
};

void insert(trieNode* head, int n){
	trieNode* curr = head;
	for(int i=31;i>=0;i--){
		int rightmostbit = (n>>i)&1;
		if(rightmostbit == 0){
			if(!curr->left){
				curr->left = new trieNode();
			}
			curr = curr->left;
		}else{
			if(!curr->right){
				curr->right = new trieNode();
			}
			curr = curr->right;
		} 
	}
}

int maxXorPair(trieNode* head, int* arr, int n){
	int max_xor = INT_MIN;
	for(int j=0;j<n;j++){
		int el = arr[j];
		int curr_xor = 0;
		trieNode* curr = head;
		for(int i=31;i>=0;i--){
			int rightmostbit = (el>>i)&1;
			if(rightmostbit == 1){
				if(!curr->left){
					curr = curr->right;
				}else{
					curr = curr->left;
					curr_xor += pow(2,i);
				}
			}else{
				if(!curr->right){
					curr = curr->left;
				}else{
					curr = curr->right;
					curr_xor += pow(2,i);
				}
			}
		}
		max_xor = max(max_xor, curr_xor);
	}
	return max_xor;
}

int main(){
	int arr[6] ={8,1,2,15,10,5};

	trieNode *head  = new trieNode();
	for(int i=0;i<6;i++){
		insert(head, arr[i]);
	}

	cout<<maxXorPair(head,arr,6)<<endl;
}
