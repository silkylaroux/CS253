#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

vector<string> parse(string str){
    vector<string> s;
    //char apos = '\'';
    while(str.length()!= 0){
        char begin_char = str.at(0);
        //cout << begin_char << " beg\n ";
        
        
        if(begin_char == '"'){
            if(str.length()>1){
                str = str.substr(1);
                int holder = str.find_first_of('"');
                s.push_back(str.substr(0, holder));
                //cout << str << '\n';
                str = str.substr(holder+1);
                //cout << str << '\n';
            }
        }

        else if(begin_char== '\''){
            if(str.length()>=4){
                s.push_back(str.substr(0,3));
                //cout << str << '\n';
                str = str.substr(3);
                //cout << str << '\n';
            }else if(str.length() == 3){
                s.push_back(str);
                str = str.substr(2);
            }

        }
        
        else if(begin_char == '-' || isdigit(begin_char)){
            int holder = str.find_first_not_of("1234567890-");
            s.push_back(str.substr(0,holder));
            //cout << str << '\n';
            str = str.substr(holder);
            //cout << str << '\n';
        }

        else if(begin_char == '\0'){
            //cout << str << '\n';
            str = str.substr(1);
            //cout << str << '\n';
        }
        else{
            //cerr << "out";
            return s;
            //exit(0);
        }
        //cout << str <<'\n';
        str = str.substr(1);
    }
    return s;
}

int main(){

    string str = "'b' ' ' 30000 \"a string in a string\" *** -2 ' '";

    vector<string> vec = parse(str);
    for( auto ch: vec){
        cout << ch << "\n";
    }
    
 return 0;
}