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
		// int hex = (input & 0x00);
		// std::cout << std::hex << (input & 0x0f) + 0x00;
		std::cout << input<< ": " << std::setfill('0') << std::setw(2) << std::hex << (input & 0x0f) << '\n';
	} else if(input >= -2048 and input < 2048){
		std::cout << input << ": "<< std::setfill('1') << std::setw(4)<< std::hex << (input & 0x0fff) << '\n';
		// std::cout << "greater than 8 or less than -8";
	} else if (input >= -524288 and input < 524288){
		std::cout << input << ": "<< std::setfill('2') << std::setw(6)<< std::hex << (input & 0x0fffff) << '\n';
	} else if (input >= -134217728 and input < 134217728){
		std::cout << input << ": "<< std::setfill('3') << std::setw(8)<< std::hex << (input & 0x0fffffff) << '\n';
	} else {
		std::cout << input << ": "<< std::setfill('4') << std::setw(10)<< std::hex << (input & 0x0fffffffff) << '\n';
	} 
	// std::cout << "decimal: " << input;
	// std::cout << input<< ": " << std::hex << (input & 0x0ff) << '\n';
	// std::cout << std::hex << input << '\n';
	// std::cout << std::hex << (twosCompliment(input) & 0x0f);
	return 0;
}

