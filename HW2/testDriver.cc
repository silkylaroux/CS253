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
void run_serialize(int opt, int args_int, char **args_names){
    int holder = opt;
    while(holder <= args_int){
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
int main(int argc, char **argv){ 
 
    if(argc == 1){ 
        cerr << "Usage error: "<< argv[0]<< " requires more arguments\n"; 
    } 
    else{ 
        int c =0;
        while ((c = getopt (argc, argv, "usv:")) != -1){
            switch (c){
                case 's':
                    //cout << " optind: " << optind << " argc: "<<argc <<'\n';
                    run_serialize(optind, argc, argv);
                    break;
                case 'u':
                    cout << "other stuff\n";
                    break; 
            }
        }
     
    } 
     
    return 0; 
}   
