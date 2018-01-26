#include <iostream>
#include <iomanip>

// helper method to make int a 2's compliment
int twosCompliment(int num){
	return -num ;
}



int main(){
	int input;
	std::cin >> input;
	if(input >= -8 and input < 8){
		std::cout << input<< ": " << std::hex << (input & 0x0f) << '\n';
	} else if(input >= -2048 and input < 2048){
		std::cout << input << ": " << std::hex << ((input & 0x0fff) + 0x1000) << '\n';
	} else if (input >= -524288 and input < 524288){
		std::cout << input << ": " << std::hex << ((input & 0x0fffff) + 0x200000) << '\n';
	} else if (input >= -134217728 and input < 134217728){
		std::cout << input << ": " << std::hex << ((input & 0x0fffffff) + 0x30000000) << '\n';
	} else {
		std::cout << input << ": " << std::hex << ((input & 0x0fffffffff) + 0x4000000000) << '\n';
	} 
	return 0;
}

