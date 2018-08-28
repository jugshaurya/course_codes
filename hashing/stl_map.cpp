#include<iostream>

#include<unordered_map>  //-- > uses seperate chaining
#include<map> //-- > uses bst hence store in increasing order as well 
using namespace std;

int main(){
	unordered_map<string, int> mymap;
	//two ways to insert
	mymap["Mango"] = 34;
    mymap["Guava"] = 38;
    mymap["Apple"] = 95;
    mymap["Strawberry"] =  70;
    mymap["Banana"] = 80;
    mymap["Pineapple"]  = 140;

	for(pair<string, int> i:mymap){
		cout<<i.first<<"|"<<i.second<<" , ";
	}
    cout<<"\n";

    //second way to print
    int count = mymap.bucket_count();
    for(int i=0;i<count;i++){
        cout<<"Bucket "<<i<<" -> ";
        for(auto it = mymap.begin(i); it!=mymap.end(i); it++){
            cout<<it->first<<"|"<<it->second<<" , ";
        }
        cout<<endl;
    }

	return 0;
}