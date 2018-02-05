#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <vector>
#include <iterator>
#include "test.h"

using namespace std;

vector<string> parse(string str){
    vector<string> s;
    while(str.length()!= 0){
        char begin_char = str.at(0);      
        
        if(begin_char == '"'){
            if(str.length()>1){
                str = str.substr(1);
                int holder = str.find_first_of('"');
                s.push_back(str.substr(0, holder));
                
                str = str.substr(holder+1);
                
            }
        }

        else if(begin_char== '\''){
            if(str.length()>=4){
                s.push_back(str.substr(0,3));
                
                str = str.substr(3);
                
            }else if(str.length() == 3){
                s.push_back(str);
                str = str.substr(2);
            }

        }
        
        else if(begin_char == '-' || isdigit(begin_char)){
            int holder = str.find_first_not_of("1234567890-");
            s.push_back(str.substr(0,holder));
            
            str = str.substr(holder);
            
        }

        else if(begin_char == '\0'){
            
            str = str.substr(1);
            
        }
        else if(begin_char == ' '){

            return s;

        }else{
            cout << begin_char; 
            cerr << "From [parser.cc] Incorrect input found: \n";
            exit(0);
        }
        //str = str.substr(1);
    }
    return s;
}