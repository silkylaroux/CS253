#include <iostream>
#include <fstream>
#include <vector>
#include "test.h"
using namespace std;
/*
* This method is used to parse a string and return a vector filled with strings.
* It does this through the use of substrings and cutting up the sting sent in.
* It parses the string on space characters, apostrophe's, digits, and quotes.
* Example: "3 -200 'g' "hel lo"" --> vector<string> [3,-200, 'g', hel, lo].
*/
vector<string> parse(string str){
    vector<string> s;

    while(str.length()!= 0){
        char begin_char = str.at(0);      
        
        if(begin_char == '"' && str.length()>1){
                str = str.substr(1);
                int holder = str.find_first_of('"');
                //cout << str.find("\t");
                s.push_back(str.substr(0, holder));
                str = str.substr(holder+1);   

        } else if(begin_char== '\'' && str.length()>1){
            str = str.substr(1);

            int hol = str.find_first_of('\'');
            //cout <<"str len: "<< str.length()<< " holder int: " << hol << '\n';
            if(hol < 9 && hol >1 ){
                unsigned int hol2 = hol;
                if( hol2 ==  str.find_first_not_of(' ')){
                    //cout << "holder2 int: " << hol2 << " find not space"<< str.find_first_not_of(' ')<<'\n';
                    //cout << "sub "<< str.substr(hol2)<< '\n';
                    s.push_back("\'\t\'");
                    str = str.substr(hol2+1);}
                //else{
                    //cerr << "From [parser.cc] Incorrect input found: '" << str << '\n';
                    //exit(0);
                //}
            }else if(hol == 1 ){
                str = "\'"+str;
               
                if(str.length()>=4){
                    s.push_back(str.substr(0,3));
                    str = str.substr(3);
                } 

                if(str.length() == 3){
                    s.push_back(str);
                    str = str.substr(2);
                }
            }else{
                cerr << "From [parser.cc] Incorrect input found: '" << str << '\n';
                exit(0);
            }

        } else if(begin_char == '-' || isdigit(begin_char)){
            int holder = str.find_first_not_of("1234567890-");
            s.push_back(str.substr(0,holder));
            str = str.substr(holder);
            
        } else if(begin_char == '\0' || isspace(begin_char)){
            str = str.substr(1);
            
        } else{
            cerr << "From [parser.cc] Incorrect input found: " << str << '\n';
            exit(0);
        }
    }
    return s;
}