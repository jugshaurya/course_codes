/*   WINNING CB SCHOLARSHIP
Prateek Bhaiya decided to give 100% scholarships to the needy students by taking an admission test. 
However in order to avoid any losses at the institute, he came up with a solution. Coding Blocks has N 
students and M discount coupons. A student will get 100% waiver if he gets X discount coupons. 
However in order to get more discount coupons in addition to those M , Bhaiya decided that some students
 who perform badly in the admission tests, need to pay additional amount equivalent to Y discount coupons,
  i.e. good students earn discount coupons and weak students need to pay coupons to get admission. 
Find out the maximum number of students who can get 100% waiver in their admission fees. 
Note : Bhaiya will try his best to give 100% discount to maximum students possible.


Input Format:
The first line contains 4 integers N M X Y

Constraints:
1 ≤ N,M,X,Y ≤ 10^9
​​
Output Format:
The output should contain a single integer representing the maximum number of students who can get
 100% discount.

Sample Input:
Test File 1:
5 10 2 1

Test File 2:
3 10 4 2

Sample Output:
Output File 1:
5

Output File 2:
2
*/

#include <iostream>
using namespace std;

bool isPossible(long n, long m, long x, long y, long mid){
    long totalCoupans = m + (n-mid)*y;
    if(mid*x <= totalCoupans){
        return true;
    }
    
    return false;
}

int main() {
    long n,m,x,y;
    cin>>n>>m>>x>>y;

    long start = 0;
    long end = n;

    long ans = 0;
    while(start<=end){
        long mid = (start+end)/2;
        if(isPossible(n,m,x,y,mid)){
            start = mid+1;
            ans =mid;
        }else{
            end = mid-1;
        }
    }
    
    cout<<ans<<endl;
}
