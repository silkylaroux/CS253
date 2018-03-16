#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <vector> 
#include <iterator> 
#include "test.h" 
#include "test2.h"
using namespace std; 
 
/* 
* This is a helper method which takes in a number and returns a char based on 
* how big the value is. This is the tag that goes in front of the vnum
*/
char check_tag_num(long num){ 
    char temp_tag; 

    if(num <= 32767 && num >= -32768){ 
        temp_tag = 's'; 

    }else if(num >= -2147483648  && num <= 2147483647){ 
        temp_tag = 'i'; 

    } else if(num > 2147483647 || num < -2147483648){ 
        temp_tag = 'l'; 
    } 
    return temp_tag; 
} 
/*
* This is a helper function that takes in a long and returns a string;
* It is used to turn an integer into a Hex vnum, and return it in the form of a string.
* Example: 300 --> "11 2c"
*/ 
string string_from_num(long input){ 
    stringstream buffer;  

    if(input >= -8 && input < 8){ 
        buffer << setfill('0') << setw(2) << hex << ((input & 0x0f)+(0x00 << 1)) << dec ; 
    
    } else if(input >= -2048 && input < 2048){ 
        buffer<<'1' << setfill('0')<< setw(3) << hex << (input & 0x0fff) << dec;
    
    } else if (input >= -524288 && input < 524288){ 
        buffer<<'2' << setfill('0')<< setw(5) << hex << (input & 0x0fffff) << dec;
    
    } else if (input >= -134217728 && input < 134217728){ 
        buffer<<'3' << setfill('0')<< setw(7) << hex << (input & 0x0fffffff) << dec;
    
    } else if(input >= -549755813888 && input < 549755813888){ 
        buffer<<'4' << setfill('0')<< setw(9) << hex << (input & 0x0fffffffff) << dec; 

    } else if(input >= -140737488355328 && input < 140737488355328){     
        buffer<<'5' << setfill('0')<< setw(11) << hex << (input & 0x0fffffffff) << dec;

    } else if(input >= -36028797018963968 && input < 36028797018963968){ 
        buffer<<'6' << setfill('0')<< setw(13) << hex << (input & 0x0fffffffffff) << dec;
    
    } else if(input >= -576460752303423488 && input < 576460752303423488){
        buffer<<'7' << setfill('0')<< setw(15) << hex << (input & 0x0fffffffffffff) << dec;
    
    }else{
        buffer<<'8' << setfill('0')<< setw(17) << hex << (input & 0x0fffffffffffffff) << dec;

    }
 
    string holder = buffer.str(); 
    buffer.str("");

    while(holder.length()>0){ 
        buffer << holder.substr(0,2) << " ";        // This chunck of code puts formats the        
        holder = holder.substr(2);                  // string stream to have spacing before return
    } 

    return buffer.str();
 
} 

/*
* This function is void and takes in a vector of strings.
* It's purpose is to go through each of the strings in the vector and print out 
* sequentially the proper vnum for the string inside. It makes use of helper functions.
*/
void print_vector(vector<string> vec){ 
    for(auto str: vec){ 
        stringstream buff;
        
        if(isdigit(str.at(0)) || str.at(0) == '-'){ 
            long x = stol(str);                     // These lines are used to create the 
            int tag_int = check_tag_num(x);         // tag for the type of integer in the vector 
             
            buff << hex << tag_int  << " "<< dec << string_from_num(x) << '\n'; 
         
        } else if(str.at(0) == '\''){ 
            int cha = str.at(1); 
            int tag_int = 'c'; 
 
            buff << hex << tag_int << " " << setfill('0') << setw(2) << hex << cha << " " << dec << '\n'; 
 
        } else if(str.compare("false")==0){
            buff << "66"<<'\n';
            
        }else if(str.compare("true")==0){
            buff<< "74"<<'\n';
            
        } else{ 
            int tag_int = 'S'; 
            buff << hex << tag_int << " " << dec << string_from_num(str.length());
 
            for(auto ch: str){ 
                int tag_int = ch; 
                buff << hex << setfill('0') << setw(2) << tag_int  << " "<< dec; 
            }   
            buff << '\n'; 
        }
        cout << buff.str();
    }
}

string print_uns_vector(vector<string> vec){
    stringstream buffer;
    for(auto st: vec){
        buffer << st <<'\n';
    }
    return buffer.str();
} 
 