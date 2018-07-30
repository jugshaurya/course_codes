#include<iostream>
#include<string>
using namespace std;

int subsequence(string str, string* output){
	if(str.length()==0){
		output[0]=" ";
		return 1;
	}
	int outputLength =subsequence(str.substr(1), output);
	for(int i=0;i<outputLength;i++){
		output[i+outputLength] = str[0] + output[i];
	} 
	return 2*outputLength;
}

int main(){
	string str="abc";
	string* output =new string[1000];

	int outputSize = subsequence(str,output);
	cout<<"{ ";
	for(int i=0;i<outputSize;i++){
		cout<<output[i]<<" ";
	}
	cout<<"}";
	cout<<endl;

	return 0;
}