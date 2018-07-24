
    //find an element in 2d sorted array(sorted row wise and column wise)

#include <iostream>
using namespace std;
int main() {
    // cout<<"Hello World!";
    int mat[4][4] = {
                        {1,2,3,4}, {5,6,7,8}, {9,11,15,18}, {16,17,20,22}
                    };
    
    //can search each element-->O(n^2);
    //binary search in each row-->O(logn * n)
    //staircase search  O(2*n)-->implemented  here

    int key;
    cin>>key;

    int n = 4;//here

    int row = 0;
    int col = n-1;
    while(true){

        if(row<0 || col<0 || row>=n || col>=n){
            cout<<"Element not found!"<<endl;
            break;
        }
        if(mat[row][col] == key){
            cout<<row<<" "<<col<<endl;
            break;
        }else if(mat[row][col] > key){
            //search in same row but col-1
            col--;
        }else{
           //search below this row in same col
           row++; 
        }
    }
}
