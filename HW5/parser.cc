#include <iostream>
#include <vector>
#include "handler.h"
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
    
    if(begin_char == '"' && str.length()>1){            // Is string
            str = str.substr(1);
            int holder = str.find_first_of('"');
            s.push_back(str.substr(0, holder));
            str = str.substr(holder+1);   

    } else if(begin_char== '\'' && str.length()>1){     // Is char
        str = str.substr(1);

        int hol = str.find_first_of('\'');
        if(hol < 9 && hol >1 ){ //***********CHECK PURPOSE **************
            unsigned int hol2 = hol;
            if( hol2 ==  str.find_first_not_of(' ')){       // This was to handle tabs???

                s.push_back("\'\t\'");
                str = str.substr(hol2+1);}

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

    } else if(begin_char == '-' || isdigit(begin_char)){        // Is num
        int holder = str.find_first_not_of("1234567890-");
        s.push_back(str.substr(0,holder));
        str = str.substr(holder);
        
    } else if(begin_char == '\0' || isspace(begin_char)){       // Is empty
        str = str.substr(1);
        
    }else if((begin_char == 'f'|| begin_char =='t') && str.length()>=5){
                                                                // Is true/false
            if(str.substr(0,4).compare("true")==0){
                s.push_back("true");
                str = str.substr(4);
            }else if(str.substr(0,5).compare("false")==0){
                s.push_back("false");
                str = str.substr(5);
            }else{
                cerr << "From [parser.cc] Incorrect input not 'true' or 'false': " 
                        << str << '\n';
                exit(0);
            }
    } else{                                                     // Is error
        cerr << "From [parser.cc] Incorrect input found: " << str << '\n';
        exit(0);
    }
}
return s;
}