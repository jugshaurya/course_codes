#include <iostream>
#include <algorithm>
using namespace std;

class Movie{
    public:
    string title;
    int release_year;
    void print(){
        cout << title << " " << release_year << endl;
    }
};

bool compareMovieRY(Movie a, Movie b){
    if (a.release_year < b.release_year){
        return true;
    }
    return false;
}
int main(){
   
    Movie mArr[] = {
        {"baghi 2", 2010},
        {"3 idiots", 2014},
        {"interstellar", 2014},
        {"bahubali 2", 2017},
        {"shashwank redemption", 1996},
        {"wolf of wall street", 2013},
        {"titanic", 1996}
    };

    int n = sizeof(mArr)/sizeof(Movie); 

    sort(mArr, mArr + n, compareMovieRY);
    

    for (int i = 0; i < n; ++i){
        mArr[i].print();
    }
}