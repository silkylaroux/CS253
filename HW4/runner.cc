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

string run_ser(string st){
//cout << st<< '\n';
    vector<string> tokens;
    stringstream buffer;
    buffer <<st <<" ";
//cout << "runner:" << buffer.str() << '\n';
    tokens = parse(buffer.str());
    return print_vector(tokens);
}

string run_unser(string st){
//cout << st<< '\n';
    vector<string> tokens;
    stringstream buffer;
    buffer <<st;

    vector<string> vec = unserial_parse(buffer.str());
    return print_uns_vector(vec);
}

