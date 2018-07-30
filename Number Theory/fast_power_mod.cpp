#include <iostream>
#include<cmath>
using namespace std;

int powmodrec(int a, int b,int c){
    if(b == 0){
        return 1;
    }

    if(!(b&1))
        return powmodrec(((long)a*a)%c, b/2, c);
    else
        return ((long)a%c * powmodrec(((long)a*a)%c, b/2, c))%c;
} 

int main() {
    // cout<<"Hello World!";
    int max = pow(2, 8*sizeof(int) -2);
    // cout << max << endl;
    cout << powmodrec(max, 11, 535);
}
