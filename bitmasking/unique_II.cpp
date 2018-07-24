// We are given an array containg n numbers. All the numbers are present twice
 // except for two numbers which are present only once.
 // Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise ).


#include<iostream>
int main() {

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mask=0;
    for (int i = 0; i < n; i++) {
        mask^=a[i];
    }
    int result=mask;
    int count=0;
    if(!(mask&1)){
        count++;
        mask>>=1;
    }
    mask = 1;
    while(count--){
        mask<<=1;
    }

    int num1 =0;
    int num2 = 0;
    for (int i = 0; i < n; i++) {
        if((a[i]&mask)!=0){
            num1^=a[i];
        }
    }
    num2=result^num1;

    if(num1<num2){
        cout << num1<<" "<<num2 <<endl;
    }else{
        cout << num2<<" "<<num1 <<endl; 
    }

    return 0;
}