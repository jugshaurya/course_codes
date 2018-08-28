#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {

    char arr[] ="abcdcfcrg";
    int n = strlen(arr);

    int visited[256];
    for(int i = 0;i<256;i++){
        visited[i] = -1;
    }

    int current_len = 0;
    int max_length = 1;
    int startIndex = 0;
    for(int i=0;i<n;i++){
        // cout<<i<<","<< max_length << " ";
        if(visited[arr[i]] == -1 || visited[arr[i]] < startIndex){
            visited[arr[i]] = i;
            current_len++;
        }else{ 
            current_len = i - visited[arr[i]];
            startIndex = visited[arr[i]] + 1;
            visited[arr[i]] = i;
        }
        max_length = max(current_len, max_length);                
    }

    cout<<max_length<<endl;
}





