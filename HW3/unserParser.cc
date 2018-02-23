#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <vector> 
#include <iterator> 
#include <algorithm>
#include <string>
#include "test.h"
#include <unistd.h>
#include <stdlib.h>
#include "runner.h"
#include "unserParser.h"
using namespace std;

bool is_hex(char ch){
    char small_ch = tolower(ch);
    switch(small_ch){
        case 'a':
            return true;
        case 'b':
            return true;
        case 'c':
            return true;
        case 'd':
            return true;
        case 'e':
            return true;
        case 'f':
            return true;
        default:
            return false;
    }

}

string unserial_parse(string input){
    if((input.length()%2)!=0){
        cerr << " From [runner.cc]: not valid input unequal amount of hex values";
        exit(1); 
    }else{
        string token_holder = input;
        string check_sign = "";
        for(unsigned int x =0; x < token_holder.length(); x++){
            char token_char = token_holder.at(x);

            if(!isdigit(token_char) && !is_hex(token_char)){
                cerr <<" From [runner.cc]: not valid input "<< token_char << "is not valid hex value\n";
                exit(0);
            }else if(check_sign.length() == 1){
                check_sign = check_sign + token_char;
            }
        }
    return input;
    }
}