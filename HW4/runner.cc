#include <iostream> 
#include <vector> 
#include "handler.h"
#include "runner.h"
#include "unserParser.h"
using namespace std;

/*
*   This runs the serialization with the data given in a string.
*/
string run_ser(string st){
    vector<string> tokens;
    st.push_back(' ');
    tokens = parse(st);
    return print_vector(tokens);
}
/*
*   This runs the unserialization with the data given in a string.
*/
string run_unser(string st){
    vector<string> tokens;
    vector<string> vec = unserial_parse(st);
    return print_uns_vector(vec);
}

