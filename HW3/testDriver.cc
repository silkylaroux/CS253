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

long handle_int(string token_holder){
    token_holder = token_holder.substr(2);
    unsigned long len2;

    char str1 = token_holder.at(0);
    unsigned int ia = str1 - '0';
    
    if(token_holder.length()>= ((ia * 2)+1)){
        string holder = token_holder.substr(1,((ia*2)+1));
        stringstream ss2;
        //ss << hex <<str1;
        ss2 << hex <<holder;
        
        //ss >> len;
        ss2 >> len2;


        return len2;
    }
    return len2;
}



int main(){
    //string input = "73017302730373046321";
    //string input = "6321730573112c69407fffffff";
    string input = "7301730273037304632153100b4a61636b204170706c696e";
    //69 40 7f ff ff ff 
    vector<string> s;
    if((input.length()%2)!=0){
        cerr << " From [runner.cc]: not valid input uneven amount of hex values";
        exit(1); 
    }else{
        string token_holder = input;

        while(token_holder.length() > 0){
            string tag = token_holder.substr(0,2);
            //token_holder == token_holder.substr(2);
//cout << "tag " << tag << '\n';
//cout << "tag compare: " << tag << " num "<< tag.compare("73")<<'\n'; 
            if(tag.compare("74")==0){                           // check if true
                s.push_back("t");


            } else if(tag.compare("66")==0){                    // check if false
                s.push_back("f");

            } else if(tag.compare("69")==0 || tag.compare("73") == 0 || tag.compare("6c")==0){
//cout << "here0 "<< token_holder.substr(0,2)<< " char"<<'\n';
                token_holder = token_holder.substr(2);
//cout << "here0 "<< token_holder.substr(0,2)<< " char"<<'\n';  
                if(token_holder.at(0)=='0'){
//cout << "here\n";
                    s.push_back(token_holder.substr(1,1));      // just return the second hex value

                }else{
                    char str1 = token_holder.at(0);
                    unsigned int ia = str1 - '0';
                    
                    if(token_holder.length()>= ((ia * 2)+1)){
                        string holder = token_holder.substr(1,((ia*2)+1));
                        stringstream ss2;
                        //ss << hex <<str1;
                        ss2 << hex <<holder;
                        unsigned int len2;
                        //ss >> len;
                        ss2 >> len2;
                        stringstream ss;
                        ss << len2;
                        s.push_back(ss.str());
//cout << ia<< '\n';
//cout << holder<< '\n';
//cout << len2<< '\n';
cout << ss.str()<<'\n';
//cout << ss.str() << '\n';
                        token_holder = token_holder.substr(((ia*2)));
                    }
//cout<< token_holder <<'\n';
                    //token_holder = token_holder.substr(2);
//cout<< token_holder <<'\n';
                }
            } else if(tag.compare("63")==0){                                // if char
                token_holder = token_holder.substr(2);
//cout << "tag compare: " << tag << " num "<< tag.compare("63")<<'\n';

                    string str1 = token_holder.substr(0,2);
//cout << str1 << '\n';
                    stringstream ss;
                    ss << hex << str1;
                    unsigned int x;
                    ss >> x; 
                    char c = x;

                    string holder;
                    holder.push_back(c);
//cout << c<< holder << '\n';
                    s.push_back(holder);
//cout << "token hold: "<< token_holder <<'\n';
            }else if(tag.compare("53")==0){                                 // if string 
//cout << "here2\n";
                unsigned long x = handle_int(token_holder);

                char str1 = token_holder.at(0);
                unsigned int ia = str1 - '0';
//cout <<x-11<< "subustr:" << token_holder.substr(ia+1)<<'\n';
                stringstream buffer;
                token_holder = token_holder.substr(ia+1);
//cout << token_holder<<" "<<token_holder.substr(ia+1) <<'\n';
                if(token_holder.length()>=(x*2)){
                    //int y =0;
                    for(unsigned int i =0; i < x;i++){
                        stringstream ss;
                        ss << hex << token_holder.substr(i,i+2);
//cout << "strem" << ss.str() << '\n';
                        long integer;
                        char cha;
                        ss >> integer;
                        cha = integer;
//cout<<"int: "<< integer << "\n char: " << cha <<'\n';
                        ss.str("");
                        buffer << cha;

                    }
//cout << "buff " << buffer.str() << '\n';
                    s.push_back(buffer.str());
                }
                
            }
            token_holder.erase(0,2);

        }
//cout << s.size();
    for(unsigned int x = 0; x <s.size()-1; x++){
        
        cout << "vector test " << s[x] << '\n';
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
