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
/*int main(int argc, char **argv){ 
 
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
                case 'v':
                    if(argc>=optind){
                        cout << "Processing file "<<argv[optind-1]<<'\n';
                    }
                    break;
                     
            }
        }
     
    } 
     
    return 0; 
}   
*/   


void serialize(bool b, std::ostream &){
    if(b){
        run_ser("true");
    }else{
        run_ser("false");
    }    
}

void serialize(short s, std::ostream &){
    string str = to_string(s);
    run_ser(str);
}
void serialize(int i, std::ostream &){
    string str = to_string(i);
    run_ser(str);
}
void serialize(long l, std::ostream &){
    string str = to_string(l);
    run_ser(str);
}
void serialize(char c, std::ostream &){
    stringstream ss;
    ss <<'\'' << c << '\'';
    run_ser(ss.str());
}

void serialize(const std::string& str, std::ostream &){
    stringstream ss;
    ss <<'\"' << str << '\"';
    run_ser(ss.str());
}
int main(){
    ostringstream oss; 
    bool t = true;
    serialize(t,oss);
    serialize(short(8), oss);
    serialize(int(300),oss);
    serialize(long(800000), oss);
    serialize('c',oss);
    string str = "Jack";
    serialize(str,oss);
}


/*
void unserialize(std::istream &, bool &){

}
void unserialize(std::istream &, short &){

}
void unserialize(std::istream &, int &){

}
void unserialize(std::istream &, long &){

}
void unserialize(std::istream &, char &){

}
void unserialize(std::istream &, std::string &){
    
}
*/