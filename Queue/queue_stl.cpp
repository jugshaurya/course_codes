//push(), pop(), front(), empty(),  a.swap(b), swap(a,b).size(). 
#include<iostream>
#include<queue>
using namespace std;

void print(queue<int> q){
	cout<<q.size()<<endl;
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

int main(){
	
	queue<int> q1;
	for(int i=0;i<10;i++){
		q1.push(i);
	}
	cout<<"first queue"<<endl;
	print(q1);

	queue<int> q2;
	for(int i=11;i<30;i++){
		q2.push(i);
	}
	cout<<"Second queue"<<endl;
	print(q2);

	//two type of swap
	cout<<"after swapping"<<endl;
	swap(q1,q2); 
	cout<<"first queue"<<endl;
	print(q1);
	cout<<"Second queue"<<endl;
	print(q2);

	cout<<"Again swapping"<<endl;
	q1.swap(q2); 
	cout<<"first queue"<<endl;
	print(q1);
	cout<<"Second queue"<<endl;
	print(q2);

}












