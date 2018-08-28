/*  longest strictly increasing-decresing subarray*/
#include<bits/stdc++.h>
using namespace std;

void maxBitonicSubarray(int *arr, int n){
	int* lis = new int[n];
	int* lds = new int[n];
	fill(lis, lis + n, 1);
	fill(lds, lds + n, 1);

	//filling lis array
	for(int i=1;i<n;i++){
		if(arr[i]>arr[i-1]){
			lis[i] = lis[i-1] + 1;
		}
	}

	//filling lds array
	for(int i=n-1; i >=0;i--){
		if(arr[i]>arr[i+1]){
			lds[i] = lds[i+1] + 1;
		}
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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* ar = new int[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        maxBitonicSubarray(ar,n);

        delete [] ar;
    } 
}
