#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <vector>
#include <iterator>


using namespace std;


// helper method to see what the tag for an integer value is
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
                int len =0;
                stringstream buffer;
                tag = 'S';
                int holder = tag;
                cout << hex << holder << " " << dec;

                for(auto ch: str){
                    len++;
                    if(ch != '"'){
                        int holder = ch;
                        buffer << hex << holder  << " "<< dec;
                    }
                }  

                printNum(len-2);
                cout << " " << buffer.str() << '\n';

            }else if(isdigit(str.at(0)) || str.at(0) == '-'){

                stringstream in(str);
                int x = 0;                  // These lines are used to create the
                in >> x;                    // tag for the type of integer in the vector
                tag = check_tag_num(x);
                int tag_int = tag;
                
                cout << hex << tag_int  << " "<< dec;
                printNum(x);

                cout << '\n';

            // This if statement checks if the first char is a ' and if there has been
            // more than 1 it will make a space char because the line was split by empty
            // spaces
            }else if(str.at(0) == '\'' && str.length() == 1){

                check++;
                if(check == 2){             // This is the check that another ' was found
                    tag = 'c';
                    char ch = ' ';
                    int space = ch;
                    int holder = tag;

                    cout << hex << holder << " "<< hex << space <<" " << dec<< '\n';
                    check = 0;
                }
            // This is the final case, and that is a char being inbetween a single
            // quote. 
            }else if(str.at(0) == '\''){
                char ch = str.at(1);
                int cha = ch;
                int tag_int = tag;
                cout << hex << tag_int << " " << hex << cha << " " << dec << '\n';

            }
            // This is the error case in which a string, integer, or character
            // was provided somewher in the file. This will end the program.
            else{
                cerr << " Using: ./hw2 the input of one of the lines"
                << " is not a string, integer, or character\n";
                exit(0);
            }
        }

}



int main(int argc, char **argv){
    if(argc == 1){
        cerr << "Usage error"<< argv[0]<< " requires more arguments\n";
    }
    else{
    for(int x = 1; x < argc; x++){
        
        ifstream in_file(argv[x]);

        if(!in_file){
            cerr <<" Using: "<< argv[0]<< " Unable to open file: " << argv[x] << '\n';
        }

        string line;
        vector<string> tokens;

        while(getline(in_file, line)){

            stringstream iss(line);

            if(line.length() != 0){
                if(line.at(0)=='"'){
                    tokens.push_back(line);
                }else{
                    for(string s; iss >> s;){
                        tokens.push_back(s);
                    }
                }
            }
        }

        print_vector(tokens);        
    }
    }

return 0;
}