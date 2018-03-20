#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <vector> 
#include <iterator> 
#include <algorithm>
#include "test.h"
#include <unistd.h>
#include <stdlib.h>
#include "runner.h"
#include "unserParser.h"
using namespace std;

/*
*   This runs the serialization with the data given in a string.
*/
string run_ser(string st){
    vector<string> tokens;
    stringstream buffer;
    buffer <<st <<" ";

    tokens = parse(buffer.str());
    return print_vector(tokens);
}
/*
*   This runs the unserialization with the data given in a string.
*/
string run_unser(string st){
    vector<string> tokens;
    stringstream buffer;
    buffer <<st;

    vector<string> vec = unserial_parse(buffer.str());
    return print_uns_vector(vec);
}

