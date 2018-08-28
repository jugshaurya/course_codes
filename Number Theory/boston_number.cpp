// A Boston number is a composite number, the sum of whose digits is the sum of the digits of 
// its prime factors obtained as a result of prime factorization (excluding 1 ). 
// The first few such numbers are 4,22 ,27 ,58 ,85 ,94 and 121 . For example, 
// 378 = 2 × 3 × 3 × 3 × 7 is a Boston number since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7. 
// Write a program to check whether a given integer is a Boston number.


#include <iostream>
using namespace std;
#define MAX 100005
int main() {
    // cout<<"Hello World!";
    int num;
    cin>>num;

    int n = num;
    int sum = 0;
    while(n>0){
        sum += n%10;
        n/=10;
    }
    n = num;

    bool primes[MAX];
    for(int i=0;i<=MAX;i++){
        primes[i] = true;
    }
    // cout<<sum<<endl;
    primes[0] = 0;
    primes[1] = 0;
    for(int i=2;i*i<=MAX;i++){
        if(primes[i]){
            for(int j = i*i;j<=MAX;j+=i){
                primes[j] = false;
            }
        }
    }

    int sum_divisor = 0 ;
    for(int i=2;i<MAX; i++){
        if(primes[i]){
            while(n>0 && i<num && (n % i == 0)){
                int add = i;
                while(add>0){
                    sum_divisor += add % 10;
                    add /= 10;
                }
                n /= i; 
            }
        }
    }
    
    //if number n was prime than--> sum_divisor till now would be 0
     if (n > 2){
      while(n>0){
        sum_divisor = sum_divisor + (n%10);
        n/=10;
    }


    }
    
    // cout<<sum_divisor<<endl;
    if(sum != sum_divisor){
        cout<<"0"<<endl;
    }else{
        cout<<"1"<<endl;
    }   


}
