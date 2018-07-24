#include <iostream>
using namespace std;
int main() {


    int n, m;
    cin>>n>>m;

    int ** mat  = new int*[n];
    for(int i=0;i<n;i++){
        mat[i] = new int[m];
    }

    for(int i=0;i<n;i++){
        for(int j= 0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    // spiral_print

    int sr = 0;
    int sc = 0;
    int lr = n-1;
    int lc = m-1;

    while(sr<=lr  && sc<=lc){

        //print row->left to right
        for(int i = sc; i<=lc;i++){
            cout<<mat[sr][i]<<" ";
        }
        sr++;

        //print col-->top-down
        for(int i = sr; i<=lr;i++){
            cout<<mat[i][lc]<<" ";
        }
        lc--;


        //print row-> right to left
        if(sr<=lr  && sc<=lc){
            for(int i = lc; i>=sc;i--){
                cout<<mat[lr][i]<<" ";
            }
            lr--;
        }

            //print col-->down-top
        if(sr<=lr  && sc<=lc){
            for(int i = lr; i>=sr; i--){
                cout<<mat[i][sc]<<" ";
            }
            sc++;
        }
    }

    for(int i=0;i<n;i++){
        delete [] mat[i];
    }

    delete [] mat;
}
