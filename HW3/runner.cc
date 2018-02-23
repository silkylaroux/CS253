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

void run_unserialize(int opt, int args_int, char **args_names){
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
                stringstream buffer;
                while(getline(in_file, line,' ')){ 

                    if(!line.empty()){
                        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
                        buffer << line;
                    }

                }
                cout<< unserial_parse(buffer.str());
                
                //stringstream buffer;
            }
            //cout<< buffer.str(); 
        holder++;
    }
}