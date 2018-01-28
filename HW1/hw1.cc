#include <iostream>
#include <iomanip>
using namespace std;

void printNum(int input){
	// Each if statement is checking to see how many bytes are needed
	// Then it will in the cout(badcoding) go through 1 byte at a time
	// separate and space out the hex values.
	// It does this by creating a mask of 0xff00... and bit shifting 
	// to desired 8 bit length

	if(input >= -8 and input < 8){
		cout << input<< ": " << setfill('0') << setw(2) << hex << ((input & 0x0f)+(0x00 << 1)) 
		<< dec << '\n';
	
	} else if(input >= -2048 and input < 2048){
		cout << input << ": " << hex << (((input & 0x0f00) + (0x1 << 12)) >> 8) 
		<< " " << setw(2) << (input & 0x00ff) << dec << '\n';
	
	} else if (input >= -524288 and input < 524288){
		cout << input << ": " << hex << (((input & 0x0f0000) + (0x2 << 20))>>16) 
		<< " " << setw(2) << ((input & 0xff00)>>8) << " " << setw(2) 
		<< (input & 0xff) << dec << '\n';
	
	} else if (input >= -134217728 and input < 134217728){
		cout << input << ": " << hex << (((input & 0x0f000000) + (0x3 << 28))>>24)
		<< " " << setw(2) << ((input & 0xff0000)>>16)<< " " << setw(2) 
		<< ((input & 0xff00)>>8) << " " << setw(2) << (input & 0xff) << dec << '\n';
	
	} else {
		cout << input << ": " << hex << (((input & 0x0f00000000) + (0x4000000000))>>32)
		<< " " << setw(2) << ((input & 0xff000000)>>24)<< " " << setw(2) 
		<< ((input & 0xff0000)>>16)<< " " << setw(2) << ((input & 0xff00)>>8) 
		<< " " << setw(2) << (input & 0xff) << dec << '\n';
	} 

}

// This program will take in the decimal value and turn it into a hex vnum value 
// ie. it will turn it into a hex number with the first nibble being the length of
// additional bytes. To stop the program it either has to reach the end of the file, or
// you terminate it (ctrl-d in linux)
int main(){

	int input1;

    while (cin >> input1) {
        printNum(input1);        
    }

    if (!cin.eof()){
        cerr << "Read failed, but not at eof.  Must be non-numeric data.\n";
    }

	

	return 0;
}


