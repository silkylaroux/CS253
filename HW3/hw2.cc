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
   
