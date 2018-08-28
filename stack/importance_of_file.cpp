/*There are N processes to be completed. All the processes have a unique number assigned to them from 1 to N.


Now, we are given two things:

1)The calling order in which all the processes are called.
2)The ideal order in which all the processes should have been executed.

Executing a process takes 1 unit of time. Changing the position takes 1 unit of time.

We have to find out the unit of time required to complete all the process such that a process is executed
 from the ideal order only when it exists at the same index in the calling order.
 We can push the first term from the calling order to the last thus rotating the order.*/

#include<iostream>
#include<queue>
using namespace std;

int minTime(int* actual, int* ideal, int n){
    queue<int> q;
    for(int i=0;i<n;i++){
        q.push(actual[i]);
    }
    int ans = 0; 
    for(int i=0;i<n;i++){
        int count = 1; // 1 for its execution
        while(q.front() != ideal[i]){
            int topper = q.front();
            q.pop();
            q.push(topper);
            count++;
        }
        // cout<<count<<" ";
        ans+=count;
        q.pop();
    }
    return ans;
}

int main(){
    
    int n;
    cin>>n;

    int* actual = new int[n];
    int* ideal = new int[n];  

    for(int i=0;i<n;i++){
        cin>>actual[i];
    }  
    
    for(int i=0;i<n;i++){
        cin>>ideal[i];
    }  

    cout << minTime(actual, ideal, n);
    delete [] actual;
    delete [] ideal;
    
}

