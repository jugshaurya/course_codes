//converting a string to integer-->
#include <iostream>
#include <cmath>
using namespace std;

int strToInt(const char* a ,int length){
	if(length==0){
		return 0;
	}	

	return int(a[0]-'0')*pow(10,length-1) + strToInt(a+1,length-1);
}


int main(){

	char s[]="454657";
	int length = sizeof(s)-1;
	cout<<"length : "<<length<<endl;
	cout<<strToInt(s,length)<<endl;

	return 0;
}