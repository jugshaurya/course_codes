
//Q-->print number(integer) ex 2048 in words(i.e. two zero four eight)

#include <iostream>

using namespace std;

char words[][10]={ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printword(int num){
	if(num == 0){
		return;
	}
	printword(num/10);
	cout<<words[num%10]<<" ";
}

int main(){
	int num=242405;
	printword(num);
	return 0;
}