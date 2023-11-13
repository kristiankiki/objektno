#include <iostream>
#include <string>
#include <cctype>

bool isPunctuation(char c) {
	return std::ispunct(c);
}

std::string fixSentence(const std::string& input) {
	std::string result;
	bool addSpace = false;

	for (char c : input) {
		if (isPunctuation(c)) {
			addSpace = true;
		}
		else if (c == ' ') {
			if (addSpace) {
				continue; .
			}
		}
		if (addSpace) {
			result += ' ';
			addSpace = false;
		}
		result += c;
	}

	return result;
}

int main() {
	std::string input;
	std::cout << "Unesite rečenicu: ";
	std::getline(std::cin, input);

	std::string fixedSentence = fixSentence(input);

	std::cout << "Ispravna rečenica: " << fixedSentence << std::endl;

	return 0;
}