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
int main(){
    //string input = "73017302730373046321";
    string input = "632163666369";
    vector<string> s;
    if((input.length()%2)!=0){
        cerr << " From [runner.cc]: not valid input unequal amount of hex values";
        exit(1); 
    }else{
        string token_holder = input;
        //string check_sign = "";
        //for(int i; token_holder.length()>0;i++){
        bool not_zero = true;
        while(not_zero){
            string tag = token_holder.substr(0,2);
            //token_holder == token_holder.substr(2);
            //cout << token_holder.length() << "tag " << tag << '\n';
            /*if(tag.compare("74")==0){                       // check if true
                s.push_back("t");
                //token_holder == token_holder.substr(2);

            } else if(tag.compare("66")==0){                // check if false
                s.push_back("f");
                //token_holder == token_holder.substr(2);

            } else if(tag.compare("69")==0 || tag.compare("73") == 0 || tag.compare("6c")==0){
                if(token_holder.at(0)=='0'){
                    
                    s.push_back(token_holder.substr(1,1)); // just return the second hex value
                    //token_holder == token_holder.substr(2);
                }else{
                    //token_holder == token_holder.substr(2);
                    char str1 = token_holder.at(0);
                    stringstream ss;
                    ss << str1;
                    unsigned int len;
                    ss >> len;
                    if(token_holder.length()>= (len * 2)){
                        //int i = 0;
                        //for(unsigned int x = 2; x<len; x= x+2){
                        //    stringstream hex_check;
                        //    hex_check << hex << token_holder.substr(i,x);
                        //}
                        stringstream ss;
                        ss << token_holder.substr(1,(len*2));
                        //cout << ss.str() << '\n';
                        token_holder = token_holder.substr(len*2);
                    }
                    token_holder = token_holder.substr(2);
                }
            } else*/ if(tag.compare("63")==0){                                           // if char
                token_holder = token_holder.substr(2);
                //cout << "tag compare: " << tag << " num "<< tag.compare("63")<<'\n';
                if(tag.compare("63")==0){
                    //cout << token_holder <<'\n';
                    string str1 = token_holder.substr(0,2);
                    //cout << str1 << '\n';
                    stringstream ss;
                    ss << hex << str1;
                    unsigned int x;
                    ss >> x; 
                    char c = x;
                    //ss.str("");
                    //ss << c;
                    string holder;
                    holder.push_back(c);
                    //cout << c<< holder << '\n';
                    s.push_back(holder);
                    //cout << "token hold: "<< token_holder <<'\n';
                                
                }
            }else{
                token_holder == token_holder.substr(2);
            }
            //break;
            token_holder.erase(0,2);// == token_holder.substr(1);
            if(token_holder.length() <= 0){
                not_zero = false;
            }
            //cout << token_holder.length();
            //break;
        }
    for(auto ch:s){
        
        cout << "vector test " << ch << '\n';
    }
    //cout << num.get_vnum();
    //s.push_back(num);
    //return 0;
    }
    return 0;
} 

/****************
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
                    cout << " optind: " << optind << " argc: "<<argc <<'\n';
                    run_serialize(optind, argc, argv);
                    break;
                case 'u':
                    cout << "other stuff\n";
                    break; 
            }
        }
    ********************/

    /*(c = getopt (argc, argv, "usv:"));
    int holder = optind;
    while(holder <= argc){
        //cout<<"file" << argv[holder]<<'\n';
        ifstream in_file(argv[holder]); 
 
            if(!in_file){ 

                cerr <<" Using: "<< argv[0]<< " Unable to open file: " << argv[holder] << '\n'; 
            }
            else{ 
                string line; 
                vector<string> tokens; 
    
                while(getline(in_file, line, '"')){ 
                    stringstream buffer; 
                    buffer << line << " "; 
                    //cout << buffer.str();
                    tokens = parse(buffer.str());   // From parser.cc This parses the line into vector
                    print_vector(tokens);           // From printer.cc This prints the vector of vnum strings
                }
            } 
        holder++;
    }*/
    
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
        } 
    } 
     
    return 0; 
}   
*/
