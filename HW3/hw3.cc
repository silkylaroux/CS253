#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <vector> 
#include <iterator> 
#include "test.h"
#include "runner.h"
#include <unistd.h>
#include <stdlib.h>
using namespace std; 
 

/*
* Driver, and file reader for hw2 uses printer.cc and parser.cc through header file.
*/
int main(int argc, char **argv){ 
 
    if(argc == 1){ 
        cerr << "Usage error: "<< argv[0]<< " requires more arguments\n"; 
    } 
    else{ 
        int c =0;
        while ((c = getopt (argc, argv, "usv:")) != -1){
            switch (c){
                case 's':
                    run_serialize(optind, argc, argv);  // From runner.cc, it runs the specified option.
                    break;
                case 'u':
                    run_unserialize(optind, argc, argv);
                    break; 
            }
        }
     
    } 
     
    return 0; 
}   
   
