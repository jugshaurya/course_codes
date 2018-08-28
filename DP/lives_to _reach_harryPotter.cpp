#include<iostream>
#include<climits>
using namespace std;

int lives_required(int** input, int si,int sj, int r, int c){

	if(si == r-1 && sj == c-1){
		return 1;
	}

	if(si == r || sj == c){
		return INT_MAX;
	}

	int option1 = lives_required(input, si+1, sj, r, c);
	int option2 = lives_required(input, si, sj+1, r, c);
	int ans = min(option1, option2) - input[si][sj];
	if( ans<1 ){
		return 1;
	}

	return ans;
}


int main(){

	int t;
	cin>>t;

	while(t--){
		int r,c;
		cin>>r>>c;

		int** input = new int*[r];
		for(int i=0;i<r;i++){
			input[i] = new int[c];
			for(int j=0;j<c;j++){
				cin>>input[i][j];
			}
		}

		cout<<lives_required(input, 0 , 0 , r , c);
	}

}