//Queue implemented using array-->circular Queue
#include<iostream>
using namespace std;

class queue{
	
	int cs;
	int next; // next+1 == index to which we add element
	int ms;
	int* arr;	

public:
	queue(int size);//constructor
	void push(int data);
	void pop();
	int front() const;
	int size() const;
	bool empty() const;
	bool full() const;
	~queue();
};

queue::queue(int size = 5){
	cs = 0;
	ms = size;
	next = ms-1;
	arr = new int[ms];
}	

queue::~queue(){
	delete [] arr;
}

void queue::push(int data){	
	if(!full()){
		next = (next + 1) % ms;
		arr[next] = data;
		cs++;
	}else{
		cout<<"array is full"<<endl;
		return ;
	}
}

void queue::pop(){
	if(!empty()){
		cs--;
	}else{
		cout<<"queue is empty"<<endl;
		return ;
	}
}

int queue::front() const{    
    if(!empty()){
		return arr[(next + 1 - cs) % ms];
	}else{
		cout<<"queue is empty can't front"<<endl;
		return -1;
	}
}

int queue::size() const{
	return cs;
}

bool queue::empty() const{
	 return cs == 0;
}

bool queue::full() const{
	return cs == ms;
}

int main(){
	queue q;
	q.push(76);
	q.push(7);
	q.push(6);
	q.push(716);
    q.push(342);
	cout<<q.top()<<endl;
    cout<<"first pop"<<endl;
	q.pop();
	cout<<q.top()<<endl;
	cout<<q.size()<<endl;
	cout<<q.empty()<<endl;
    
    cout<<"second pop"<<endl;
	q.pop();
	cout<<q.top()<<endl;
	cout<<q.size()<<endl;
	cout<<q.empty()<<endl;

    cout<<"third pop"<<endl;
	q.pop();
	cout<<q.top()<<endl;
	cout<<q.size()<<endl;
	cout<<q.empty()<<endl;
    
    cout<<"fourth pop"<<endl;
	q.pop();
	cout<<q.top()<<endl;
	cout<<q.size()<<endl;
	cout<<q.empty()<<endl;
    
    cout<<"fifth pop"<<endl;
	q.pop();
	cout<<q.top()<<endl;
	cout<<q.size()<<endl;
	cout<<q.empty()<<endl;

    q.pop();
}










