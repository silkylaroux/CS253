#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <vector> 
#include <iterator>
#include <cassert> 
#include "test.h"
#include "runner.h"
#include <unistd.h>
#include <stdlib.h>
using namespace std; 

string remove_spaces(string str) 
{
//cout << "rm_sp" << str << '\n';
    string retStr;
    for(auto ch: str ){
//cout << "rm_sp ch:" << ch << '\n';
        if(ch!=' '){
//cout << "rm_sp ch:" << ch << '\n';
            retStr.push_back(ch);
            
        }
    }
//cout << retStr;
    return retStr;
}

void de_hexify(string input, std::ostream& os){
    //stringstream ss;
    string s;
    //string st;
    input = remove_spaces(input);   
// cout <<"\ninput: " << input <<'\n';
    int i_hex;
    //for (int x = 0; x < input.length()-1; x+=2){
    while(input.length()>1){
        stringstream ss;
        ss << input.substr(0,2);
// cout << "de_hex" << ss.str() << '\n';
        unsigned int value;
        ss >> std::hex >> value;
        //unsigned int temp = sHex; // sHex holds the full hex value (including nibble) ex: 8 -> 0x1008
        value = value & 0xff; // takes one byte at a time, starting with most significant
//cout << char(value);
        os << char(value); 
        s += char(value);
//cout << value<<"hmmm\n";
        //is >> hex >> i_hex;
//cout<< setfill('0')<< setw(2)<<hex<<i_hex<<'\n';

//cout << i_hex;
        //ss << setw(2)<<hex<< i_hex;
        //os<< value;
        input = input.substr(2);
    }
//cout << s.at(1) <<" "<< "\x10\x08"<<'\n';
//cout << hex << ss.str().at(1) << "comp: " << '\x10' << '\n';
//cout <<ss.str().compare("s" "\x10\x08");

//cout << os.str();
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
    cout << str;   
}
void serialize(short s, std::ostream & os){
    string str = to_string(s);
    str = run_ser(str);
    str = str.substr(2,str.length());
    str.insert(0,"73");

    de_hexify(str, os);
    cout << str;

}
void serialize(int i, std::ostream & os){
    string str = to_string(i);
    str = run_ser(str);
    str = str.substr(2,str.length());
    str.insert(0,"69");

    de_hexify(str, os);
    cout << str;
}
void serialize(long l, std::ostream & os){
    string str = to_string(l);
    str = run_ser(str);
    str = str.substr(2,str.length());
    str.insert(0,"6c");

    de_hexify(str, os);
    cout << str;
}
void serialize(char c, std::ostream & os){
    stringstream ss;
    ss <<'\'' << c << '\'';
    string str = run_ser(ss.str());
    de_hexify(str,os);

    cout << run_ser(ss.str());
}
void serialize(const std::string& strg, std::ostream & os){
    stringstream ss;
    ss <<'\"' << strg << '\"';
    string str = run_ser(ss.str());
    de_hexify(str,os);

    cout << run_ser(ss.str());
}

// This is a helper method that takes a string, and turns each char
// in the string into a "hex" string 
// example: hexify("Jack")  returns "4a61636b"
string hexify(string input){
    stringstream str;
    for (int i = 0; i < input.length(); i++)
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
cout << i << '\n';
}

void unserialize(std::istream & is, short & sh){
    string s;
    is >> s;
    string st = run_unser(hexify(s));

    istringstream (st) >> sh;
cout << sh << '\n';
}

void unserialize(std::istream & is , long & l){
    string s;
    is >> s;
    string st = run_unser(hexify(s));

    istringstream (st) >> l;
cout << l << '\n';
}

void unserialize(std::istream & is, char & c){
    string s;
    is >> s;
    string st = run_unser(hexify(s));

    istringstream (st) >> c;
cout << c << '\n';
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
cout << st << '\n';
}

int main(){
    cout << "serialized!\n";
    ostringstream oss; 
    bool t = true;
    serialize(t,oss);
    assert(oss.str()=="t");

    ostringstream osssh; 
    serialize(short(8), osssh);		  // ctor “cast”
    assert(osssh.str() == "s" "\x10\x08");

    ostringstream ossi;
    serialize(int(8),ossi);
    assert(ossi.str() == "i" "\x10\x08");

    oss.str("");
    serialize(0x123456789abcdef0L, oss);
    assert(oss.str() == "l\x80\x12\x34\x56\x78\x9a\xbc\xde\xf0"s);

    serialize('c',oss);
    string str = "Jack";
    serialize(str,oss);
    
    cout << "\nunserialized!\n";
    bool b1, b2;
    istringstream iss;
    iss.str("tf");
    unserialize(iss, b1); unserialize(iss, b2); assert(b1 && !b2);

    istringstream isss;
    string st;
    isss.str("S\x10\x0c"s "kakistocracy");
    unserialize(isss, st); assert(st == "kakistocracy");

    istringstream issc;
    char c;
    issc.str("\x63\x21"s);
    unserialize(issc, c);

    istringstream iss2;
    int i;
    iss2.str({'i', '\x2e', '\x1d', '\xc0'});
    unserialize(iss2, i); //assert(i == -123456);
    
    istringstream iss3;
    short s;
    iss3.str({'s', '\x1f','\xac'});
    unserialize(iss3, s); //assert(s == -123456);

    //6c 41 c8 f6 5a 34
    istringstream iss4;
    long l;
    iss4.str({'l', '\x41', '\xc8', '\xf6', '\x5a', '\x34'});
    unserialize(iss4, l); //assert(i == -123456);
    //iss.str("");


}


