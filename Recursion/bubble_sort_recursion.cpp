#include<iostream>
using namespace std;

void bubbleSort(int a[], int length ){
//sorting in ascending order// using one for-loop
	//Base Case
	if(length==1){
		return ;
	}

	//Ind. step
	//in bubble sort First we  bubble one element to its position then sort . 
	for(int j=0;j<length;j++){
	    if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
	    }
	}
	
	bubbleSort(a,length-1);
}

/*
* j-->inner loop variable
*/
void bubbleSort2(int a[],int j, int length ){
//sorting in ascending order// without using loop i.e we are converting innerloop into recursive call as well
	//Base Case
	if(length==1){
		return ;
	}

	if(j == length-1){
		return bubbleSort2(a,0,length-1);
	}

	if(a[j]>a[j+1]){
		swap(a[j],a[j+1]);
	}	
	bubbleSort2(a,j+1,length);
}

int main(){

	int a[]={3,6,7,9,8,32,5,0,7};
	int size = sizeof(a)/sizeof(int);
    
    cout<<"Before: "<<endl;    
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	
	cout<<endl;
	//bubbleSort(a,size);
	bubbleSort2(a,0,size);
	
    cout<<"After: "<<endl;
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}