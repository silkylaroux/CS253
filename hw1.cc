#include <iostream>
int main(){
	int input;
	std::cin >> input;
	if(input >= -8 and input < 8){
		int hex = (input & 0x0f);
		std::cout <<hex;
		std::cout << input<< ": " << std::hex << (input & 0xff) << '\n';
	} else{
		std::cout << "greater than 8 or less than -8";
	}
	// std::cout << "decimal: " << input;
	// std::cout << input<< ": " << std::hex << (input & 0x0ff) << '\n';
	return 0;
}
