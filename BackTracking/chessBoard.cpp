/*Take as input N, a number. N represents the size of a chess board.
 We’ve a piece standing in top-left corner and it must reach the bottom-right corner. 
 The piece moves as follows –

a. In any cell, the piece moves like a knight. But out of the possible 8 moves for a knight,
 only the positive ones are valid i.e. both row and column must increase in a move.

b. On the walls (4 possible walls), the piece can move like a rook as well (in addition of knight moves). 
But, only the positive moves are allowed i.e. as a rook, piece can move any number of steps horizontally or 
vertically but in a manner, such that row or column must increase.

c. On the diagonals (2 possible diagonals), the piece can move like a bishop as well 
(in addition to the knight and possibly rook moves). But, only the positive moves are allowed i.e. as a bishop,
 piece can move in a way such that row and column must increase.

You are supposed to write the following functions

a. Write a recursive function which returns the count of different distinct ways this board can be
 crossed. Print the value returned.

b. Write a recursive function which prints all valid paths (void is the return type for function).*/

#include <iostream>
using namespace std;

int count(int n, int i, int j){
    
    if(i == n-1 && j == n-1){
        return 1;
    }
    
    if(i>=n || j>=n){
        return 0;
    }
    
    int opt1=0, opt2=0, opt3=0;
    
    if(i==j){
        opt1 +=count(n,i+1,j+1);
    }
    
    if(i==0 || j==0 || i==n-1 || j==n-1){
        opt2 += count(n,i+1,j) + count(n,i,j+1);
    }
    
    opt3 += count(n, i+2, j+1) + count(n, i+1, j+2);
    return opt3+opt2+opt1;
}

void print(int n, int i, int j, pair<int,char> mat[10][10]){
    
    if(i == n-1 && j == n-1){
        //print the path
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
                if(mat[x][y].first == 1){
                    cout <<"{" << x <<"-" <<y <<"}"<< mat[x][y].second;
                }
            }
        }
        cout <<"{" << n-1 <<"-" << n-1 <<"}";
        cout<<" ";
        return;
    }
    
    if(i>=n || j>=n){
        return ;
    }
    
    if(mat[i][j].second != 'i'){
        return ;
    }
    
    
    
    //moving Rook
    if(i==0 || j==0 || i==n-1 || j == n-1){
        mat[i][j]  = make_pair(1,'R');
        print(n,i,j+1,mat);
        print(n,i+1,j,mat);
        mat[i][j]  = make_pair(0,'i');
    }     
    //Moving Bishop
    if(i == j){
        mat[i][j] = make_pair(1,'B');
        print(n,i+1,j+1, mat);
        mat[i][j] = make_pair(0,'i');
    }
    //moving Knight
    mat[i][j] = make_pair(1,'K');
    print(n, i+1, j+2, mat);
    print(n, i+2, j+1,mat);
    mat[i][j] = make_pair(0,'i');
    
}

int main() {
    
    
    int n;
    cin>>n;
    
    pair<int,char> mat[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            mat[i][j] = make_pair(0,'i');
        }
    }
    
    cout<<count(n,0,0)<<endl;
    print(n,0,0,mat);
}

