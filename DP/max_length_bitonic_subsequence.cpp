/*  longest strictly increasing-decresing subsequence*/
#include<bits/stdc++.h>
using namespace std;

void maxBitonicSubSequence(int arr[], int n){
	int* lis = new int[n];
	int* lds = new int[n];
	fill(lis, lis + n, 1);
	fill(lds, lds + n, 1);

	//filling lis array
	for(int i=1;i<n;i++){
		int maxi = 1;
		for(int j=0;j<i;j++){
			if(arr[j] < arr[i]){
				maxi = max(maxi, lis[j] + 1);
			}
		}
		lis[i] = maxi;
	}

	//filling lds array
	for(int i= n-2;i>=0;i--){
		int maxi = 1;
		for(int j = i+1;j<n;j++){
			if(arr[j] < arr[i]){
				maxi = max(maxi, lds[j] + 1);
			}
		}
		lds[i] = maxi;
	}

	int maxi = lis[0] + lds[0] - 1;
	for(int i=1;i<n;i++){
		maxi = max(maxi, lis[i] + lds[i] - 1);
	}
	cout<<maxi<<endl;    

    delete [] lis;
    delete [] lds;
}	

int main(){
    int n;
    cin>>n;
    
	int *arr =new int[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	maxBitonicSubSequence(arr,n); 
}
