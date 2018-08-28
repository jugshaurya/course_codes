/*
    
STOCK SPAN PROBLEM
You are given an array of length N, where ith element of array denotes the price of a stock on ith.
 Find the span of stock's price on ith day, for every 1<=i<=N.
A span of a stock's price on a given day, i, is the maximum number of consecutive days before the (i+1)th day,
 for which stock's price on these days is less than or equal to that on the ith day.


Input Format:
First line contains the number of test cases, T. For each test case, first line contains a single integer N, 
denoting the number of days. Next line contains N integers, ith of which denotes the stock's price on ith day.

Constraints:
1<=T<=10
1<=N<=10^5
1<=Stock's price<=10^9
Output Format:
Print a single line containing N integers. ith integer denotes the stock span for the ith day.

Sample Input:
1
5
1 2 4 3 5
Sample Output:
1 2 3 1 5 

*/
/*
    b is A[i+1] and a is A[i].
    hintSolved -> 
    1. if b<a  answer is 1;
    2. if(b==a) then answer is top+1 ,pop the top and push new ans with el.
    3. if(b>a) then add answer of all elements in stack till b < a(strictly less than) answer is additionANS +1 
                        and push it back..
                        see the implementation
*/




#include<iostream>
#include<stack>
using namespace std;

int main(){
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        
        int el;
        stack<pair<int,int> > s;
        cin>>el;
        s.push(make_pair(el,1));
        cout<<1<<" ";
        for(int i =1;i<n;i++){
            cin>>el;
            // cout<<i<<flush<<s.size()<<el<<endl;;
            if(el< s.top().first){
                cout<<1<<" ";
                s.push(make_pair(el,1));
            }else if(el == s.top().first){
                int ans = s.top().second+1;
                cout<< s.top().second + 1 <<" ";
                s.pop();
                s.push(make_pair(el, ans));
            }else{
                //el > top el of stack
                int count = 1;
                while(!s.empty() && s.top().first <= el  ){
                    count += s.top().second;
                    s.pop();
                }
                cout<<count<<" ";
                s.push(make_pair(el, count));
            }
        }
    }
}
