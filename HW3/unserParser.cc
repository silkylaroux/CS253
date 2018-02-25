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
long handle_int(string token_holder){
    token_holder = token_holder.substr(2);
    unsigned long len2;

    char str1 = token_holder.at(0);
    unsigned int ia = str1 - '0';
    
    if(token_holder.length()>= ((ia * 2)+1)){
        string holder = token_holder.substr(1,((ia*2)+1));
        stringstream ss2;
        ss2 << hex <<holder;
        ss2 >> len2;
        
        return len2;
    }
    return len2;
}
char getchar_str(int i, string token_holder2){
    unsigned long x;                 
    stringstream ssnew;

    ssnew<< hex <<token_holder2.substr(i,i+2);

    ssnew >> x;
    unsigned char cha;
    cha = x;

    return cha;

}

vector<string> unserial_parse(string input){
    vector<string> s;
    if((input.length()%2)!=0){
        cerr << " From [runner.cc]: not valid input uneven amount of hex values";
        exit(1); 
    }else{
        string token_holder = input;

        while(token_holder.length() > 0){
            string tag = token_holder.substr(0,2);
 
            if(tag.compare("74")==0){                           // check if true
                s.push_back("t");

            } else if(tag.compare("66")==0){                    // check if false
                s.push_back("f");

            } else if(tag.compare("69")==0 || tag.compare("73") == 0 || tag.compare("6c")==0){
                token_holder = token_holder.substr(2);
                if(token_holder.at(0)=='0'){
                    s.push_back(token_holder.substr(1,1));      // just return the second hex value

                }else{
                    char str1 = token_holder.at(0);
                    unsigned int ia = str1 - '0';
//cout << "len: "<< ia;
                    if(token_holder.length()>= ((ia * 2)+1)){
                        string holder = token_holder.substr(1,((ia*2)+1));
//cout << "str: " << holder <<'\n';
                        stringstream ss2;
                        ss2 << hex <<holder;
                        unsigned long len2;
//cout <<"len: " << len2<<'\n';
                        ss2 >> len2;
//cout <<"len: " << len2<<'\n';
                        stringstream ss;
                        ss << len2;
cout << "lon: "<< static_cast<long>(len2);
                        s.push_back(ss.str());

                        token_holder = token_holder.substr(((ia*2)));
                    }
                }
            } else if(tag.compare("63")==0){                                // if char
                token_holder = token_holder.substr(2);

                    string str1 = token_holder.substr(0,2);

                    stringstream ss;
                    ss << hex << str1;
                    unsigned int x;
                    ss >> x; 
                    char c = x;

                    string holder;
                    holder.push_back(c);
                    s.push_back(holder);

            }else if(tag.compare("53")==0){                                 // if string 
                unsigned long x = handle_int(token_holder);
                
                char str1 = token_holder.at(0);
                unsigned int ia = str1 - '0';
                
                stringstream buffer;
                token_holder = token_holder.substr(ia+1);
                if(token_holder.length()>=(x*2)){
                    
                    string temp = token_holder.substr(0,(x*2));
                    while(temp.length()>0){
                        buffer << getchar_str(0,temp); 
                        temp = temp.substr(2);
                    }

                    token_holder = token_holder.substr((x*2)-2);
                    s.push_back(buffer.str());
                }
                
            }else{
                cerr << "From: [unserParser.cc] incorrect input: " << tag << " is not a valid tag for a vnum.";
                exit(1);
            }
            token_holder.erase(0,2);
        }
    }
    return s;
}