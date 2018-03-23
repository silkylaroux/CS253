#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <vector> 
#include "handler.h"
#include "runner.h"
//#include <cassert> 
using namespace std; 

string remove_spaces(string str) 
{
    string retStr;
    for(auto ch: str ){
        if(ch!=' '){
            retStr.push_back(ch);
        }
    }
    return retStr;
}

// This is a helper method that takes a string, and adds each char
// to the ostream that is sent in
// example: hexify("Jack")  ostream << "\x4a\x61\x63\x6b"
void de_hexify(string input, std::ostream& os){
    input = remove_spaces(input);   

    while(input.length()>1){
        stringstream ss;
        ss << input.substr(0,2);

        unsigned int value;
        ss >> std::hex >> value;

        value = value & 0xff; // takes one byte at a time, starting with most significant
        os << char(value); 

        input = input.substr(2);
    }
} 

void serialize(bool b, std::ostream & os){
    string str;
    if(b){
        str = run_ser("true");
        de_hexify(str,os);

    }else{
        str = run_ser("false");
        de_hexify(str,os);
    } 
}
void serialize(short s, std::ostream & os){
    string str = to_string(s);
    str = run_ser(str);
    str = str.substr(2,str.length());
    str.insert(0,"73");

    de_hexify(str, os);
}
void serialize(int i, std::ostream & os){
    string str = to_string(i);
    str = run_ser(str);
    str = str.substr(2,str.length());
    str.insert(0,"69");

    de_hexify(str, os);
}
void serialize(long l, std::ostream & os){
    string str = to_string(l);
    str = run_ser(str);
    str = str.substr(2,str.length());
    str.insert(0,"6c");

    de_hexify(str, os);
}
void serialize(char c, std::ostream & os){
    stringstream ss;
    ss <<'\'' << c << '\'';
    string str = run_ser(ss.str());
    de_hexify(str,os);
}
void serialize(const std::string& strg, std::ostream & os){
    stringstream ss;
    ss <<'\"' << strg << '\"';
    string str = run_ser(ss.str());
    de_hexify(str,os);

}

// This is a helper method that takes a string, and turns each char
// in the string into a "hex" string 
// example: hexify("Jack")  returns "4a61636b"
string hexify(string input){
    stringstream str;
    for (unsigned int i = 0; i < input.length(); i++)
    {
        unsigned char x = input.at(i);
        str<< setfill('0')<<setw(2) <<hex << int(x);
    }
    return str.str();
}

void unserialize(std::istream& is, bool& b){
    char c;
    is >> c;

    if(c == 't'){
        b = true;
    }else if(c == 'f'){
        b = false;
    }else{
        cerr << "oops\n";
    }
}

void unserialize(std::istream & is, int & i){
    string s;
    is >> s;
    string st = run_unser(hexify(s));

    istringstream (st) >> i;
}

void unserialize(std::istream & is, short & sh){
    string s;
    is >> s;
    string st = run_unser(hexify(s));

    istringstream (st) >> sh;
}

void unserialize(std::istream & is , long & l){
    string s;
    is >> s;
    string st = run_unser(hexify(s));

    istringstream (st) >> l;
}

void unserialize(std::istream & is, char & c){
    string s;
    is >> s;
    string st = run_unser(hexify(s));

    istringstream (st) >> c;
}

void unserialize(std::istream & is, std::string & st){
    string s;
    stringstream ss;
    while(getline(is,s)){
        ss << s;
    }
    s = hexify(ss.str());
    st = run_unser(s);
    st.pop_back();                          // removes unwanted \n from back
}
