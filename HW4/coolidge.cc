    #include "functions.h"
    #include <iostream>
    #include <sstream>
    #include <fstream>
    #include <cassert>

    using namespace std;

    int main() {

        cout << "Test begins\n";

        ostringstream oss;
        serialize(short(8), oss);		  // ctor “cast”
        assert(oss.str() == "s" "\x10\x08");  // beware: \x00 ≡ \0 ≡ end of string

        oss.str("");
        serialize(0x123456789abcdef0L, oss);
        assert(oss.str() == "l\x80\x12\x34\x56\x78\x9a\xbc\xde\xf0"s); 

        try {
            bool b1, b2;
            istringstream iss("tf");
            unserialize(iss, b1); unserialize(iss, b2); assert(b1 && !b2);

            int i;
            iss.str({'i', '\x2e', '\x1d', '\xc0'});
            unserialize(iss, i); assert(i == -123456);

            // string str;
            // iss.str("S\x10\x0c"s "kakistocracy");
            // unserialize(iss, str); 
            // cout << str;
            // assert(str == "kakistocracy");

            istringstream isss;
            string st;
            isss.str("S\x10\x0c"s "kakistocracy");
            unserialize(isss, st); assert(st == "kakistocracy");
        }
        catch (string msg) {
            cerr << "Unserialize error: " << msg << '\n';
        }

        // Ensure that fstreams also work
        ofstream ofs;
        serialize("!@#$%^&*()", ofs);   // expected to quietly fail
        assert(!ofs);

        cout << "Test ends\n";
        return 0;
    }