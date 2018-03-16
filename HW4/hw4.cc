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

string hexify(string input){
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

void unserialize(std::istream& is, bool& b){
    char c;
    //s = is.get();
    is >> c;
//cout <<"s:" << s << '\n';
    //string st = run_unser(hexify(s));
//cout << st <<'\n';
    if(c == 't'){
        b = true;
    }else if(c == 'f'){
        b = false;
    }else{
        cerr << "oops\n";
    }
}

void unserialize(std::istream & is, int &){
    string s;
    is >> s;
    string st = run_unser(hexify(s));

    long i;
    istringstream (st) >> i;
cout << i << '\n';
}

void unserialize(std::istream & is, short &){
    string s;
    is >> s;
    string st = run_unser(hexify(s));

    short sh;
    istringstream (st) >> sh;
cout << sh << '\n';
}

void unserialize(std::istream & is , long &){
    string s;
    is >> s;
    string st = run_unser(hexify(s));

    long l;
    istringstream (st) >> l;
cout << l << '\n';
}

void unserialize(std::istream & is, char &){
    string s;
    is >> s;
    string st = run_unser(hexify(s));
//cout << st << '\n';
    char c;
    istringstream (st) >> c;
cout << c << '\n';
}

void unserialize(std::istream & is, std::string &){
    string s;
    stringstream ss;
    while(getline(is,s)){
        ss << s;
    }
//cout << ss.str()<<'\n';
    s = hexify(ss.str());
    string st = run_unser(s);
    st.pop_back();                          // removes unwanted \n from back
cout << st << '\n';
}

int main(){
    cout << "serialized!\n";
    ostringstream oss; 
    bool t = true;
    serialize(t,oss);
    serialize(short(8), oss);
    serialize(int(300),oss);
    serialize(long(800000), oss);
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
    unserialize(isss, st); //assert(str == "kakistocracy");

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


