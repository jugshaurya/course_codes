#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

#define hashmap unordered_map<char, trieNode*>

class trieNode{
public:
	char data;
	hashmap h;
	bool isTerminal;

	trieNode(char ch){
		isTerminal = false;
		data = ch;
	}
};

class trieClass{
	void addWordHelper(trieNode*, string);
public:
	trieNode* root ;
	
	trieClass(){
		root = new trieNode('\0');
	}
	
	void addWord(string str){
		return addWordHelper(root, str);
	}

    bool isPresent(string str);
};

void  trieClass::addWordHelper(trieNode* root,  string str){
	if(str.length() == 0){
		root->isTerminal = true;
		return ;
	}

	if(root->h.count(str[0]) == 1){
		addWordHelper(root->h[str[0]] , str.substr(1));
	}else{
		trieNode* childNode = new trieNode(str[0]);
		(root->h)[str[0]]  = childNode;
		addWordHelper(root->h[str[0]] , str.substr(1));
	}

}

bool trieClass::isPresent(string str){
    trieNode* temp = root;
    for(int i=0;i<(int)str.length(); i++){
        if(temp->h.count(str[i])){
            temp = temp->h[str[i]];
        }else{
            return false;
        }
    }

    return temp->isTerminal;
}

int main(){
	trieClass trie;
	trie.addWord("shaurya");
	trie.addWord("apple");
	trie.addWord("mango");
	trie.addWord("not");
	trie.addWord("no");

    cout<<boolalpha<<trie.isPresent("shaurya")<<endl;
    cout<<boolalpha<<trie.isPresent("man")<<endl;
    cout<<boolalpha<<trie.isPresent("")<<endl;
    cout<<boolalpha<<trie.isPresent("no")<<endl;
    cout<<boolalpha<<trie.isPresent("mango")<<endl;
}