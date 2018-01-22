#include <iostream>
int main(){
	int input;
	std::cin >> input;
	std::cout << "decimal: " << input;
	std::cout << "hex: " << std::hex << (input & 0xff) << '\n';
	return 0;
}
