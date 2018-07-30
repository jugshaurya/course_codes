#include<iostream>

using namespace std;

int binarySearch(int *a, int start, int end, int key){
	//Base case
	if(start > end){
		return -1;
	}
	//recusive step
	int mid = (start + end) / 2;
	if(a[mid]==key){
		return mid;
	}
	if(a[mid]>key){
		//Search over left side
		return binarySearch(a,start,mid-1,key);
	}else{
		//Search over right side
		return binarySearch(a,mid+1,end,key);
	}
}

int main(){

	int a[]={1,2,3,6,7,9,11};
	int n=sizeof(a)/sizeof(int);
	int key=11;
	cout<<binarySearch(a,0,n,key)<<endl;
	return 0;
}