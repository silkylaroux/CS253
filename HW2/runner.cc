#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <vector> 
#include <iterator> 
#include "test.h"
#include <unistd.h>
#include <stdlib.h>
#include "runner.h"
using namespace std; 


void run_serialize(int opt, int args_int, char **args_names){
    int holder = opt;
    while(holder < args_int){
        //cout<<"file" << argv[holder]<<'\n';
        ifstream in_file(args_names[holder]); 
 
            if(!in_file){ 
                cerr <<" Using: "<< args_names[0]<< " Unable to open file: " << args_names[holder] << '\n'; 
            }
            else{ 
                string line; 
                vector<string> tokens; 
    
                while(getline(in_file, line)){ 
                    stringstream buffer; 
                    buffer << line << " "; 
                    //cout << buffer.str();
                    tokens = parse(buffer.str());   // From parser.cc This parses the line into vector
                    print_vector(tokens);           // From printer.cc This prints the vector of vnum strings
                }
            } 
        holder++;
    }
}