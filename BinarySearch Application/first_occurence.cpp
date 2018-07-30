// given a sorted array find first occuence of a value


#include<iostream>
using namespace std;

int first_occ(int arr[], int n, int key){
	int start = 0;
	int end = n-1;

	int ans = -1;
	while(start<=end){
		int mid = (start+end)/2;
		if(arr[mid] == key){
			ans = mid;
			end = mid -1;
		}else if(arr[mid]> key){
			end = mid-1;
		}else{
			start = mid+1;
		}
	}

	return ans;
}

int main(){

	int arr[] = {2,2,3,4,4,5,5,6,6,6,7,8};
	int size = sizeof(arr)/sizeof(int);

	int key = 9; 
	int index = first_occ(arr, size,key);
	cout<<index<<endl;

	return 0;
}