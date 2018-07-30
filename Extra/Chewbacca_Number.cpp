// Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them.
 // Inverting digit t means replacing it with digit 9 - t.
// Help Chewbacca to transform the initial 
// number x to the minimum possible positive number by inverting some (possibly, zero) digits.
 // The decimal representation of the final number shouldn't start with a zero.

#include <iostream>
using namespace std;
int main() {
    // cout<<"Hello World!";
    char arr[20];
    cin>>arr;

    int value = arr[0]-'0';
    if( value != 9 && (9 - value) < value){
        arr[0] = 9 - value + 48;
    }

    for(int i=1;arr[i]!='\0';i++){
        int digit = arr[i] - '0';
        if(9-digit < digit){
            arr[i] = 9 - digit + 48;
        }
    }
    cout<<arr;
}
