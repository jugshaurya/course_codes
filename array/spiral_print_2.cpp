#include <iostream>
using namespace std;
int main() {

    int n, m;
    cin>>n>>m;

    // spiral_print_2

    int sr = 0;
    int sc = 0;
    int lr = n-1;
    int lc = m-1;

    char ** output  = new char*[n];
    for(int i=0;i<n;i++){
        output[i] = new char[m];
    }

    char ch = 'O';
    while(sr<=lr  && sc<=lc){

        //print row->left to right
        for(int i = sc; i<=lc;i++){
            output[sr][i] = ch;
        }
        sr++;

        //print col-->top-down
        for(int i = sr; i<=lr;i++){
           output[i][lc] = ch;
        }
        lc--;


        //print row-> right to left
        if(sr<=lr  && sc<=lc){
            for(int i = lc; i>=sc;i--){
                output[lr][i] = ch;
            }
            lr--;
        }

            //print col-->down-top
        if(sr<=lr  && sc<=lc){
            for(int i = lr; i>=sr; i--){
                output[i][sc] = ch;
            }
            sc++;
        }

        if(ch =='O'){
            ch = 'X';
        }else{
            ch = 'O';
        }
    }

    // printing output
    for(int i=0;i<n;i++){
        for(int j= 0;j<m;j++){
            cout<<output[i][j];
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++){
        delete [] output[i];
    }

    delete [] output;

}
