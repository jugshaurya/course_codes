#include<iostream>
#include<algorithm>

using namespace std;

int partition(int *a,int start, int end){
	//Choose a pivot element let say the end one
	int pivot = a[end];
	int i=start; //denotes the position of upcoming element lesser than pivot
	int j=i; //denotes the element tracking element over which comparision happen
	while(j<end){
		if(a[j]<=pivot){
			swap(a[i],a[j]);
			i++;
		}
		j++;
	}
	//at last put pivot at its correct position that is i now
	swap(a[i],a[j]);
	return i;
}

void quickSort(int *a,int start, int end){
	//Base Case
	if(start>=end){
		return;
	}

	//we have 3 step here
	
	//1.Choose pivot element ,arrange data accordingly and Get the correct position of pivot element 
	int pIndex = partition(a,start,end);
	//2. sort the left sub-array
	quickSort(a,start,pIndex-1);
	//3. sort the right sub-array
	quickSort(a,pIndex+1,end);
}

int main(){

	int a[]={1,2,3,4,5,7,8,9};
	int size=sizeof(a)/sizeof(int);
	//for randomized quickSort 
	random_shuffle(a,a+size);	
	// can also use srand(time(null)) with rand() to generate random index and reverse each index element accordingly. 
	cout<<"Before: "<<endl;    
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	//sorting elements
	quickSort(a,0,size-1);
	
    cout<<"After: "<<endl;
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}