//compute the square root of a number using binary search
#include<iostream>
using namespace std;

double mysqrt(int n){
	// getting the integer part
	int start = 0;
	int end = n;
	int mid;
	double ans;
	while(start<=end){
		mid = (start+end)/2;
		if(mid*mid == n){
			ans =  mid;
			break;
		}
		if(mid*mid < n){
			ans = mid;
			start = mid+1;
		}
		if(mid*mid >n){
			end = mid-1;
		}
	}
	// upto three precision
	int p = 3;
	double fraction = 0.1;
	for(int i=0;i<p;i++){
		for(int i=0;i<=9;i++){
			ans = ans + fraction;
			if(ans*ans > n ){
				ans = ans - fraction;
				fraction = fraction/10;
				break;
			}
		}
	}
	return ans;
}

int main(){

	int a = 49;
	int b = 24;

	cout<<mysqrt(a)<<endl;
	cout<<mysqrt(67)<<endl;
	cout<<mysqrt(9723)<<endl;
	cout<<mysqrt(b)<<endl;

	return 0;
}