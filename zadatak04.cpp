#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

bool isVowel(char c) {
	
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

std::string translateToPigLatin(const std::string& sentence) {
	std::istringstream iss(sentence);
	std::string word;
	std::string translatedSentence;

	while (iss >> word) {
		if (isVowel(word[0])) {
			
			translatedSentence += word + "hay ";
		}
		else {
			
			std::string consonants;
			while (!isVowel(word[0]) && !word.empty()) {
				consonants += word[0];
				word = word.substr(1);
			}
			translatedSentence += word + consonants + "ay ";
		}
	}

	
	if (!translatedSentence.empty()) {
		translatedSentence.pop_back();
	}

	return translatedSentence;
}

int main() {
	std::vector<std::string> sentences;

	
	std::string input;
	while (true) {
		std::cout << "Unesite englesku rečenicu (ili pritisnite Enter za završetak unosa): ";
		std::getline(std::cin, input);

		if (input.empty()) {
			break;
		}

		sentences.push_back(input);
	}

	
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	if (!sentences.empty()) {
		int randomIndex = std::rand() % sentences.size();
		std::string pigLatinSentence = translateToPigLatin(sentences[randomIndex]);
		std::cout << "Prevedena rečenica: " << pigLatinSentence << std::endl;
	}
	else {
		std::cout << "Nema unetih rečenica." << std::endl;
	}

	return 0;
}