#include <iostream>
#include<cstdlib>
#include <string>
using namespace std;

string arr_oct[] = {"000","001","010","011","100","101","110","111"};
string arr_hex[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};

string octToDec(string value){
    if(value[0] == '\0'){
        return "";
    }

    return arr_oct[value[0]-'0'] + octToDec(value.substr(1));
}

string hexToDec(string value){
    if(value[0] == '\0'){
        return "";
    }
    if((value[0]-'0')<=9){
        return arr_hex[value[0]-'0'] + hexToDec(value.substr(1));
    }else{
        return arr_hex[value[0]-'a'+10] + hexToDec(value.substr(1));
    }
}

string decToHexHelper(int value){
    if(value == 0){
        return "";
    }    

    if(value%16 <=9)
        return decToHexHelper(value/16) + to_string(value % 16);
    else{
        return decToHexHelper(value/16) + char( 97 + (value % 16 - 10));
    }
}

string decToHex(string value){
    const char* ch = value.c_str();
    return decToHexHelper(atoi(ch));
}

string decToOctHelper(int value){
    if(value == 0){
        return "";
    }    

    return decToOctHelper(value/8) + to_string(value % 8);
}

string decToOct(string value){
    const char* ch = value.c_str();
    return decToOctHelper(atoi(ch));
}

string octToHex(string value){
    string intermission = octToDec(value);
    return decToHex(intermission);
}

string hexToOct(string value){
    string intermission = hexToDec(value);
    return decToOct(intermission);
}
