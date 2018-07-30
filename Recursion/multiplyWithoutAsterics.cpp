#include <iostream>
using namespace std;

int multiply(int a, int b){
	//Initial Needs
	/*1*/
	int sign=0;
	/*2*/
	if(a<0){
		sign++;
		a=-a;
	}
	if(b<0) {
		sign++;
		b=-b;
	}
	/*3*/
	if(a==0 || b==0) return 0;
	//Base Cond.
	if( b==1 ) return a; 
	//Induction Hypothesis
	if(sign==0 || sign==2)
		return  a + multiply(a, b-1);
	if(sign==1)
		return -(a + multiply(a, b-1));
}

int main()
{
	cout<<multiply(3,7)<<endl;
	cout<<multiply(-3,7)<<endl;
	cout<<multiply(3,-7)<<endl;
	cout<<multiply(-3,-7)<<endl;

	cout<<multiply(0,3)<<endl;
	cout<<multiply(-3,0)<<endl;
	cout<<multiply(3,0)<<endl;
	cout<<multiply(-3,0)<<endl;

	return 0;
}