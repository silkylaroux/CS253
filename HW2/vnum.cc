#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <vector>
#include <iterator>


using namespace std;

int bit_size;
char tag;
int num;

int get_size(){
    return bit_size;
}

char get_tag(){
    return tag;
}



char check_tag_num(int num){
    char temp_tag;
    if(num < 32767){
        temp_tag = 's';
    }
    if(num >= 32767 && num < 2147483647){
        temp_tag = 'i';
    }
    if(num >= 2147483647){
        temp_tag = 'l';
    }
    return temp_tag;
}

void printNum(int input){
	// Each if statement is checking to see how many bytes are needed
	// Then it will in the cout(badcoding) go through 1 byte at a time
	// separate and space out the hex values.
	// It does this by creating a mask of 0xff00... and bit shifting 
	// to desired 8 bit length

	if(input >= -8 and input < 8){
		cout << setfill('0') << setw(2) << hex << ((input & 0x0f)+(0x00 << 1)) 
		<< dec ;
	
	} else if(input >= -2048 and input < 2048){
		cout << hex << (((input & 0x0f00) + (0x1 << 12)) >> 8) 
		<< " " << setw(2) << (input & 0x00ff) << dec;
	
	} else if (input >= -524288 and input < 524288){
		cout << hex << (((input & 0x0f0000) + (0x2 << 20))>>16) 
		<< " " << setw(2) << ((input & 0xff00)>>8) << " " << setw(2) 
		<< (input & 0xff) << dec;
	
	} else if (input >= -134217728 and input < 134217728){
		cout << hex << (((input & 0x0f000000) + (0x3 << 28))>>24)
		<< " " << setw(2) << ((input & 0xff0000)>>16)<< " " << setw(2) 
		<< ((input & 0xff00)>>8) << " " << setw(2) << (input & 0xff) << dec;
	
	} else {
		cout << hex << (((input & 0x0f00000000) + (0x4000000000))>>32)
		<< " " << setw(2) << ((input & 0xff000000)>>24)<< " " << setw(2) 
		<< ((input & 0xff0000)>>16)<< " " << setw(2) << ((input & 0xff00)>>8) 
		<< " " << setw(2) << (input & 0xff) << dec;
	} 

}

void print_vector(vector<string> vec){
        int check =0;
        char tag;
        for(auto str: vec){
            if(str.at(0) == '"'){

                tag = 'S';
                int holder = tag;
                cout << hex << holder << " " << dec;

                for(auto ch: str){
                    if(ch != '"'){
                        int holder = ch;
                        cout << hex << holder  << " "<< dec;
                    }
                }      
            }else if(str.at(0) != '\''){
                stringstream in(str);
                int x = 0;
                in >> x;
                char ch = check_tag_num(x);
                int holder = ch;
                cout << ch << " " << hex << holder  << " "<< dec;
                printNum(x);
            }else if(str.at(0) == '\'' && str.length() == 1){
                check++;
                if(check == 1){
                    char ch = ' ';
                    int holder = ch;
                    cout << hex << holder << " " << dec;
                    check = 0;
                }
            }else{
                char ch = str.at(1);
                int holder = ch;
                cout << hex << holder << " " << dec;

            }
            cout << '\n';
        }

}



int main(int argc, char **argv){
    
    for(int x = 1; x < argc; x++){
        
        ifstream in_file(argv[x]);
        if(!in_file){
            cerr << " Unable to open file: " << argv[x] << '\n';
        }

        string line;
        vector<string> tokens;

        while(getline(in_file, line)){
                stringstream iss(line);
                //vector<string> tokens;
                if(line.length() != 0){
                    if(line.at(0)=='"'){
                        tokens.push_back(line);
                    }else{
                        for(string s; iss >> s; )
                        tokens.push_back(s);
                    }
                }
        }
        for(auto tok: tokens){
            cout << tok << '\n';
        }
        print_vector(tokens);
        //cout<< '\n';
        
    }
    

return 0;
}