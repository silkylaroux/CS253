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
 

/*
* Driver, and file reader for hw2 uses printer.cc and parser.cc through header file.
*/
/*int main(int argc, char **argv){ 
 
    if(argc == 1){ 
        cerr << "Usage error: "<< argv[0]<< " requires more arguments\n"; 
    } 
    else{ 
        int c =0;
        while ((c = getopt (argc, argv, "usv:")) != -1){
            switch (c){
                case 's':
                    run_serialize(optind, argc, argv);  // From runner.cc, it runs the specified option.
                    break;
                case 'u':
                    run_unserialize(optind, argc, argv);
                    break;
                case 'v':
                    if(argc>=optind){
                        cout << "Processing file "<<argv[optind-1]<<'\n';
                    }
                    break;
                     
            }
        }
     
    } 
     
    return 0; 
}   
*/   


void serialize(bool b, std::ostream &){
    if(b){
        run_ser("true");
    }else{
        run_ser("false");
    }    
}

void serialize(short s, std::ostream &){
    string str = to_string(s);
    run_ser(str);
}
void serialize(int i, std::ostream &){
    string str = to_string(i);
    run_ser(str);
}
void serialize(long l, std::ostream &){
    string str = to_string(l);
    run_ser(str);
}
void serialize(char c, std::ostream &){
    stringstream ss;
    ss <<'\'' << c << '\'';
    run_ser(ss.str());
}

void serialize(const std::string& str, std::ostream &){
    stringstream ss;
    ss <<'\"' << str << '\"';
    run_ser(ss.str());
}

void unserialize(std::istream& is, bool& b){
    stringstream str;
    str << hex << is.get();
    //is >> str;
    //cout << hex << is.get() <<'\n';
    run_unser(str.str());
    /*char c = is.get();
    //cout << c;
    if(c =='t'){
        b = true;
    }else if(c == 'f'){
        b = false;
    }else{
        cerr << "oops\n";
    }*/
}
string hexify(string input)
{
    stringstream str;
//cout << input <<" " << input.length()<< "x:\n";
    for (int i = 0; i < input.length(); i++)
    {
        unsigned char x = input.at(i);
//cout << x <<'\n';
//cout << setw(2) << hex << x<<'\n';
        
        str<< setfill('0')<<setw(2) <<hex << int(x);
    }
    return str.str();
}

void unserialize(std::istream & is, int &){
    string s;
    is >> s;
    run_unser(hexify(s));
}

void unserialize(std::istream & is, short &){
    string s;
    is >> s;
    run_unser(hexify(s));
}

void unserialize(std::istream & is , long &){
    string s;
    is >> s;
    run_unser(hexify(s));
}

void unserialize(std::istream & is, char &){
    string s;
    is >> s;
    run_unser(hexify(s));
}

void unserialize(std::istream & is, std::string &){
    string s;
    stringstream ss;
    //is >> s;
    //ss <<s;
    while(getline(is,s)){
//cout << s<<'\n';
        ss << s;
    }
    s = hexify(ss.str());

//cout << hexify(s2.str());
    run_unser(s);
}

int main(){
    ostringstream oss; 
    /*bool t = true;
    serialize(t,oss);
    serialize(short(8), oss);
    serialize(int(300),oss);
    serialize(long(800000), oss);
    serialize('c',oss);
    string str = "Jack";
    serialize(str,oss);
    */

    //bool b1, b2;
    istringstream iss;
    //unserialize(iss, b1); unserialize(iss, b2); assert(b1 && !b2);

    //int i;
    //iss.str({'i', '\x2e', '\x1d', '\xc0'});
    //unserialize(iss, i); assert(i == -123456);

    short s;
    iss.str({'s', '\x1f','\xac'});
    unserialize(iss, s); //assert(s == -123456);

    //long l;
    //iss.str({'i', '\x2e', '\x1d', '\xc0'});
    //unserialize(iss, i); assert(i == -123456);

    //string str;
//cout<<setfill('0')<<setw(2) << hex << int('\x0c') << '\n';
    //iss.str("S\x10\x0c"s "kakistocracy");
    //string s;
    //iss.get();
    //iss.get();
    //s = iss.str();

//cout << hexify(s);
    //unserialize(iss, str); //assert(str == "kakistocracy");

    char c;
    iss.str("\x63\x21"s);
    unserialize(iss, c);
}


