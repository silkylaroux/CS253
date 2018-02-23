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

bool is_hex_char(char ch){
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
bool check_tag(string str){

}

string unserial_parse(string input){
    vector<string> s;
    if((input.length()%2)!=0){
        cerr << " From [runner.cc]: not valid input unequal amount of hex values";
        exit(1); 
    }else{
        string token_holder = input;
        string check_sign = "";

        while(token_holder.length()>0){
            string tag = token_holder.substr(0,2);
            if(tag.compare("66")==0 || tag.compare("74")){
                s.push_back(tag);
                token_holder = token_holder.substr(3);
            }else{
                s.push_back(tag);
                token_holder = token_holder.substr(3);
                int num;
                num << hex <<
            }

        }



        for(unsigned int x =0; x < token_holder.length(); x++){
            char token_char = token_holder.at(x);

            if(!isdigit(token_char) && !is_hex_char(token_char)){
                cerr <<" From [unserParser.cc]: not valid input "<< token_char << "is not valid hex value\n";
                exit(0);
            }else if(check_sign.length() == 1){
                check_sign = check_sign + token_char;
                if()
            }
        }
    return input;
    }
}