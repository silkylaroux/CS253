#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include "test.h"

using namespace std;
int main(int argc, char **argv){
    int holder = argc;
    holder++;
    vector<std::string> vec;
    std::string str = "5 300 -1 " ;
    string str2;
    ifstream infile(argv[1]);
    getline(infile,str2);
    cout<< str2 <<"\n";

    vec = parse(str);
    for( auto ch: vec){
        cout << ch << "\n";
    }
    return 0;
}