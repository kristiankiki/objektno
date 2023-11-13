#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


std::string reverseString(const std::string& str) {
	std::string reversedStr = str;
	std::reverse(reversedStr.begin(), reversedStr.end());
	return reversedStr;
}

int main() {
	std::vector<std::string> strings;
	std::string input;

	
	while (true) {
		std::cout << "Unesite string (ili pritisnite Enter za završetak unosa): ";
		std::getline(std::cin, input);

		if (input.empty()) {
			break;
		}

		strings.push_back(reverseString(input)); 
	}

	
	std::sort(strings.begin(), strings.end());

	
	std::cout << "Sortirani preokrenuti stringovi: " << std::endl;
	for (const std::string& reversedStr : strings) {
		std::cout << reverseString(reversedStr) << std::endl;
	}

	return 0;
}