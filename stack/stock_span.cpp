//find the position i need to jump back to get the first largest value than my current element

#include <iostream>
#include<stack>
using namespace std;
int main() {
    // cout<<"Hello World!";
    int n;
    cin>>n;

    stack<pair<int,int> > s;
    int data;
    cin>>data;
    int count=0;
    int ans[100];
    ans[count++] = 0;
    s.push(make_pair(0,data)); 
    for(int j=1;j<n;j++){
        cin>>data;
        int topEl = s.top().second;
        if(data > topEl){
            while( data > topEl){
                s.pop();
                topEl = s.top().second;
            }
        }
        ans[count++] = j - s.top().first;
        s.push(make_pair(j,data));
    }

    for(int j=0;j<count;j++){
        cout<<ans[j]<<" ";
    }

    cout<<"END";
}









