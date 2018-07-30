#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare_function(int i, int j){
   return i > j;    // return 1 if i>j else 0
}
bool compare_string(string i, string j){ 
  return (i.size() < j.size()); 
}

int main(){
  int arr[5] = {1,5,8,4,2};
  
  sort(arr , arr+5);   
  vector<int> v1;
  
  v1.push_back(8);
  v1.push_back(4);
  v1.push_back(5);
  v1.push_back(1);

  vector<int>::iterator i, j;
  
  i = v1.begin();   
  j = v1.end();     

  sort(i,j);     
  int a2[] = { 4,3,6,5,6,8,4,3,6 };
    
  sort(a2,a2+9,compare_function);
   
  string s[]={"a" , "abc", "ab" , "abcde"};

  sort(s,s+4,compare_string);
}