#include <iostream>
int main(){
	int input;
	std::cin >> input;
	std::cout << input + 1;
	std::cout << "hex: " << std::hex << (input & 0xff) << '\n';
	return 0;
}
