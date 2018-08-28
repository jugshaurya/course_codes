#include<iostream>
#include<queue>
using namespace std;

void print(queue<int> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}

	cout<<endl;
}

//using implicit stack -->can use explicit as well
void reverse_queue(queue<int>& q){

	if(q.empty()){
		return;
	}
	int topElement = q.front();
	q.pop();
	reverse_queue(q);
	q.push(topElement); 
}


int main(){

	queue<int> q;
	for(int i=0;i<5;i++){
		q.push(i);
	}

	print(q);

	reverse_queue(q);
	print(q);
}