#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <vector> 
#include <iterator> 
#include "test2.h"
using namespace std; 

string Vnum::get_vnum(){
    return vnum;
    }
void Vnum::make_vnum(string str){
    //vector<string> vec = parse(str);
    
    vnum = print_vector(str);
}

Vnum::Vnum(string str){
    make_vnum(str);
}
