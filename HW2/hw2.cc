#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <vector> 
#include <iterator> 
#include "test.h"
using namespace std; 
 

/*
* Driver, and file reader for hw2 uses printer.cc and parser.cc through header file.
*/
int main(int argc, char **argv){ 
 
    if(argc == 1){ 
        cerr << "Usage error: "<< argv[0]<< " requires more arguments\n"; 
    } 
    else{ 
        for(int x = 1; x < argc; x++){ 
             
            ifstream in_file(argv[x]); 
 
            if(!in_file){ 

                cerr <<" Using: "<< argv[0]<< " Unable to open file: " << argv[x] << '\n'; 
            }
            else{ 
                string line; 
                vector<string> tokens; 
    
                while(getline(in_file, line)){ 
                    stringstream buffer; 
                    buffer << line << " "; 
    
                    tokens = parse(buffer.str());   // From parser.cc This parses the line into vector
                    print_vector(tokens);           // From printer.cc This prints the vector of vnum strings   
                }
            } 
        } 
    } 
     
    return 0; 
}   
