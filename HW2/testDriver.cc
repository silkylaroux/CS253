#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include "test2.h"
#include <unistd.h>
#include <stdlib.h>

using namespace std;
/*int main(){
    string str = "3 400 -222 ";
    vector<string> s = parse(str);

    vector<Vnum> vnum_vec;
    for(auto st: s){
        Vnum num(st);
        vnum_vec.push_back(num);
    }
    for(auto p: vnum_vec){
        cout << p.get_vnum();
    }
    
    //cout << num.get_vnum();
    //s.push_back(num);
    return 0;
} */

int main(int argc, char **argv){ 
 
    if(argc == 1){ 
        cerr << "Usage error: "<< argv[0]<< " requires more arguments\n"; 
    } 
    else{ 
        int c =0;
        while ((c = getopt (argc, argv, "usv:")) != -1){
            switch (c){
                case 's':
                    cout << "stuff\n";
                    break;
                case 'u':
                    cout << "other stuff\n";
                    break; 
            }
        }
    //(c = getopt (argc, argv, "usv:"));
    int holder = optind;
    while(holder <= argc){
        cout<<"file" << argv[holder]<<'\n';
        holder++;
    }
    
        /*for(int x = 1; x < argc; x++){ 
             
            ifstream in_file(argv[x]); 
 
            if(!in_file){ 

                cerr <<" Using: "<< argv[0]<< " Unable to open file: " << argv[x] << '\n'; 
            }
            else{ 
                string line; 
                vector<string> tokens; 
    
                while(getline(in_file, line, '"')){ 
                    stringstream buffer; 
                    buffer << line << " "; 
                    cout << line.find_first_of('\t') << " \n";
                    tokens = parse(buffer.str());   // From parser.cc This parses the line into vector
                    print_vector(tokens);           // From printer.cc This prints the vector of vnum strings   
                }
            } 
        }*/ 
    } 
     
    return 0; 
}   
