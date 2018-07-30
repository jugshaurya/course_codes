#include <iostream>
using namespace std;

bool fun(int a, int b){
    cout<<"faf"<<endl;
    cout<<a<<b<<endl;
    return true;
}

void func(int a , int b, bool (*function) (int , int) ){

    cout<<a<<b<<" wsfa "<<endl;
    function(a, b);
    cout<<"agaga"<<endl;
}

int main() {
    //can be called using function pointer
    bool (*functor)(int, int) = &fun;
    functor(43,56); 
    cout<<"fsafsagsgagsgf"<<endl;

    //can be passed to function a function.
    func(2,3,fun);
}
