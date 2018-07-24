#include <iostream>
using namespace std;

int main() {
	int a[10][10];
	int R,C;
	cin>>R>>C;

	//Read into Matrix
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			a[i][j]=i+j;
		}
	}

	//Print Matrix
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//wave Print
    cout<<"Wave Print"<<endl;
    for (int j = 0; j < C; ++j){
        
        if(j&1){
            //odd column
            for (int i = R-1; i>=0; --i){
			    cout<<a[i][j]<<" ";
		    }
        }else{
            //even column
             for (int i =0; i<=R-1; ++i){
			    cout<<a[i][j]<<" ";
		    }
        }
	}
	return 0;
}