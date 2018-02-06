#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <vector> 
#include <iterator> 
#include "test2.h" 
 
using namespace std; 
 
/* 
*   This is a helper method which takes in a number and returns a char based on 
*   how big the value is. This is the tag that goes in front of the vnum
*/
char check_tag_num(long num){ 
    char temp_tag; 
    if(num < 32767 && num > -32768){ 
        temp_tag = 's'; 
    } 
    else if(num > -2147483648  && num < 2147483647){ 
        temp_tag = 'i'; 
    } 
    else if(num >= 2147483647 || num <= -2147483648){ 
        temp_tag = 'l'; 
    } 
    return temp_tag; 
} 
 
string string_from_num(long input){ 

 stringstream buffer;  
  if(input >= -8 and input < 8){ 
    buffer << setfill('0') << setw(2) << hex << ((input & 0x0f)+(0x00 << 1)) << dec ; 
   
  } else if(input >= -2048 and input < 2048){ 
    buffer << setfill('0') << hex << (((input & 0x0fff) + (0x1 << 12))) << dec; 
   
  } else if (input >= -524288 and input < 524288){ 
    buffer << setfill('0') << hex << (((input & 0x0fffff) + (0x2 << 20))) << dec;          
   
  } else if (input >= -134217728 and input < 134217728){ 
    buffer << setfill('0') << hex << ((input & 0x0fffffff) + (0x3 << 28)) << dec; 
   
  } else { 
    buffer << setfill('0') << hex << (((input & 0x0fffffffff) + (0x4000000000))) << dec; 
    }  
 
    string holder = buffer.str(); 
    buffer.str("");
        while(holder.length()>0){ 
            buffer << holder.substr(0,2) << " ";    // This chunck of code puts formats the        
            holder = holder.substr(2);              // string stream to have spacing before return
        } 
    return buffer.str();
 
} 
 
string print_vector(string str){ 
 
    //for(auto str: vec){ 
        stringstream buff;
        if(isdigit(str.at(0)) || str.at(0) == '-'){ 
 
            stringstream in(str); 
            long x = 0;                             // These lines are used to create the 
            in >> x;                                // tag for the type of integer in the vector 
            int tag_int = check_tag_num(x); 
             
            buff << hex << tag_int  << " "<< dec << string_from_num(x) << '\n'; 
         
        }else if(str.at(0) == '\''){ 
            int cha = str.at(1); 
            int tag_int = 'c'; 
 
            buff << hex << tag_int << " " << hex << cha << " " << dec << '\n'; 
 
        }else{ 

            int tag_int = 'S'; 
            buff << hex << tag_int << " " << dec << string_from_num(str.length());
 
            for(auto ch: str){ 

                int tag_int = ch; 
                buff << hex << tag_int  << " "<< dec; 
            }   
 
             
            buff << '\n'; 
        }    
    return buff.str();
    //}
    //return NULL;     
} 