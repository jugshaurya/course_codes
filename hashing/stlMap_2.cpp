#include<iostream>
//insert(), erase(), count(), bucket_count()
#include<unordered_map>  //-- > uses seperate chaining
#include<map> //-- > uses bst hence store in increasing order as well 
using namespace std;

class fruit{
public:
    string name;
    int price;
    string color;

    fruit(){    // internally search function make a garbage obj na.....

    }

    fruit(string n, int p, string c):name(n),price(p),color(c){
    }

    void print(){
        cout<<name<<" "<<price<<" "<<color;
    }
};

int main(){
    unordered_map<string, fruit> mymap;
    fruit arr[] = {{"Mango", 100, "yellow"},
                    {"Guava", 60, "Green"},
                    {"Apple", 55, "Red"},
                    {"Strawberry", 34, "Pink"}};
    
    for(int i=0;i<4;i++){
        mymap.insert(make_pair(arr[i].name, arr[i]));
    }

    fruit f = mymap["Apple"]; //searching + insertion into map
    f.print();
    cout<<endl;

     fruit f2 = mymap["Applee"]; //searching + insertion into map
    f2.print();
    cout<<endl;

    //count() ->just searching not inserting
    cout<<mymap.count("Apple")<<endl;
    cout<<mymap.count("Applee")<<endl;
    cout<<mymap.count("Appleee")<<endl;
    //see output by commenting next line and then see with it...
    mymap.erase("Applee");

    
    mymap.erase("Mango");
    for(pair<string, fruit> i:mymap){
        fruit f = i.second;
        f.print();
        cout<<endl;
    }
    cout<<"\n";

    return 0;
}