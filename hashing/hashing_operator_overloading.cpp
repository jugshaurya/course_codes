#include<iostream>
#include<cmath>
using namespace std;

class node{
public:
    string key;
    int value;
    node* next;
    node(string k, int d){
        key = k;
        value = d;
        next = NULL;
    }

    ~node(){
        if(next!=NULL){
            delete next;  //recursive destructor call...
        }
    }
};

class hashmap{
    node** bucket;
    int tableSize ;
    int cs;      // current size

    int hashfunction(string str);
    void rehash();
    void addToHead(node*& root,string key, int data){
        node* temp = new node(key,data);
        temp->next = root;
        root = temp;
    }
public:
    hashmap(int);
    ~hashmap();
    void insert(string key, int value);
    int* search(string key);
    void print();
    int& operator[](string);
};

int hashmap::hashfunction(string str){
        int len = str.length();
        int p = 1;
        int key = 0;
        for(int i = len-1; i>=0; i--){
            int digit = str[i];
            key += (digit * p);
            key %= tableSize;
            p = p*37;
            p = p % tableSize;
        }

        return key;
}

hashmap::hashmap(int n = 11){
    tableSize = n;
    cs = 0;
    bucket = new node*[n];
    for(int i=0;i<tableSize ;i++){
        bucket[i] = NULL;
    }
}

hashmap::~hashmap(){
    delete [] bucket;
}

void hashmap::rehash(){
    //double the table size and put elements into it
    int oldSize = tableSize; 
    tableSize = 2* tableSize;
    cs = 0;
    node** oldBucket = bucket;
    
    bucket = new node*[tableSize];
    for(int i=0; i<tableSize; i++){
        bucket[i] = NULL;        
    }
    
    //read the elements from old table and insert into bucket...
    for(int i=0;i<oldSize;i++){
        node* temp = oldBucket[i];
        while(temp!=NULL){
            string key  = temp->key;
            int value = temp->value;
            insert(key,value);
            temp = temp->next;
        }
    }

    for(int i=0;i<oldSize;i++){
        if(oldBucket[i]!=NULL){
            delete oldBucket[i];
        }
    }

    delete[] oldBucket;
}

void hashmap::insert(string key, int value){
    int keyIndex = hashfunction(key);
    int* alreadyExist = search(key);
    if(alreadyExist == NULL){
        cs++;
        addToHead(bucket[keyIndex],key,value);
    }else{
        //updating if that key-value pair already exist...
        *alreadyExist = value;
    }

    float loadfactor = (float)cs/tableSize;
    if(loadfactor > 0.7){
        cout<<"rehashing "<<loadfactor<<endl;
        rehash();
    }
}

int* hashmap::search(string key){
    int keyIndex = hashfunction(key);
    node* temp = bucket[keyIndex];
    
    while(temp!=NULL && temp->key != key){
        temp = temp->next;
    }

    if(temp == NULL){
        return NULL;
    }
    return &(temp->value);
}

void hashmap::print(){
    for(int i=0;i<tableSize;i++){
        node* temp = bucket[i];
        cout<<"Bucket "<<i<<" : ";
        while(temp != NULL){
            cout<<temp->key<<"|"<<temp->value<<" --> ";
            temp = temp->next;
        }
        cout<<endl;
    }    
}

// operator overloading
int& hashmap::operator[](string key){
    int* box = search(key);
    if(box!=NULL){
        return *box;
    }
    else{
        int garbage;
        insert(key,garbage);
        box = search(key);
        return *box;
    }
}


int main(){
    hashmap h(5);

    h["Mango"] = 34;
    h["Mango"] = 43;
    h["Guava"] = 38;
    h["Apple"] = 95;
    h["Strawberry"] =  70;
    h["Banana"] = 80;
    h["Mango"]  = 55;
    h["Pineapple"]  = 140;

    h.print(); 
    cout<<h["Strawberry"];
   
    return 0;
}