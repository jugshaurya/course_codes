#include <iostream>
#include<cstdlib>
#include<cmath>
#include <string>
using namespace std;

string decToOct(string);
string decToHex(string);

string arr_oct[] = {"000","001","010","011","100","101","110","111"};
string arr_hex[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};

string remove_zeros(string output){
    int breakIndex = -1 ;
    for(int i=0; output[i]!='\0';i++){
        // cout<<output<<endl;
        if(output[i] == '0'){
            breakIndex++;
        }else{
            break;
        }
    }

    string value = "";
    for(int i= breakIndex + 1; output[i]!='\0';i++){
        value += output[i];
    }

    return value;
}

//Binary to Dec,oct ,Hex
string binaryToDec(string value){
    int length = value.size();
    long long ans = 0;
    int p = 0;
    for(int i = 0 ;i<length;i++){
         ans += pow(2,p) * (value[length-1-i]-'0');
         p++;
    }
    return to_string(ans);
}

string binaryToOct(string value){
    string intermission = binaryToDec(value);
    return decToOct(intermission);
}

string binaryToHex(string value){
    string intermission = binaryToDec(value);
    return decToHex(intermission);
}

//decimal to others
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

string decToBinHelper(int value){
    if(value == 0){
        return "";
    }    

    return decToBinHelper(value/2) + to_string(value % 2);
}

string decToOctHelper(int value){
    if(value == 0){
        return "";
    }    

    return decToOctHelper(value/8) + to_string(value % 8);
}

string decToHex(string value){
    const char* ch = value.c_str();
    return decToHexHelper(atoi(ch));
}

string decToOct(string value){
    const char* ch = value.c_str();
    return decToOctHelper(atoi(ch));
}

string decToBin(string value){
    const char* ch = value.c_str();
    return decToBinHelper(atoi(ch));
}

//Octal to other
string octToBin(string value){
    if(value[0] == '\0'){
        return "";
    }

    return arr_oct[value[0]-'0'] + octToBin(value.substr(1));
}

string octToDec(string value){
    int length = value.size();
    int ans = 0;
    int p = 0;
    for(int i = 0 ;i<length;i++){
         ans += pow(8,p) * (value[length-1-i]-'0');
         p++;
    }
    return to_string(ans);   
}

string octToHex(string value){
    string intermission = octToDec(value);
    return decToHex(intermission);
}

//hex to others
string hexToBin(string value){
    if(value[0] == '\0'){
        return "";
    }
    if((value[0]-'0')<=9){
        return arr_hex[value[0]-'0'] + hexToBin(value.substr(1));
    }else{
        return arr_hex[value[0]-'a'+10] + hexToBin(value.substr(1));
    }
}

string hexToDec(string value){
    int length = value.size();
    int ans = 0;
    int p = 0;
    for(int i = 0 ;i<length;i++){
        if(value[length-1-i]>='a' && value[length-1-i]<='f'){
            ans += pow(16,p) * (value[length-1-i] -'a'+10);
        }else{
            ans += pow(16,p) * (value[length-1-i] -'0');
        }
         p++;
    }
    return to_string(ans);   
}

string hexToOct(string value){
    string intermission = hexToDec(value);
    return decToOct(intermission);
}

int main(){

    int ss,ds;
    cin>>ss>>ds;

    string num;
    cin>>num;

    switch(ss){
        case 2 :
                switch(ds){
                    case 8 :
                        cout<<binaryToOct(num);
                        break;
                    case 10 :
                        cout<<binaryToDec(num);
                        break;
                    case 16 :
                        cout<<binaryToHex(num);
                        break;
                }
                break;

        case 8 : 
                switch(ds){
                    case 2 :
                        cout<<remove_zeros(octToBin(num));
                        break;
                    case 10 :
                        cout<<octToDec(num);
                        break;
                    case 16 :
                        cout<<octToHex(num);
                        break;
                }
                break;

        case 10 :
                switch(ds){
                    case 2 :
                        cout<<decToBin(num);
                        break;
                    case 8 :
                        cout<<decToOct(num);
                        break;
                    case 16 :
                        cout<<decToHex(num);
                        break;
                }
                break;

        case 16 : 
                switch(ds){
                    case 2 :
                        cout<< remove_zeros(hexToBin(num));
                        break;
                    case 8 :
                        cout<<hexToOct(num);
                        break;
                    case 10 :
                        cout<<hexToDec(num);
                        break;
                }
                break;
    }
}


