#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <string>

void processFile(const std::string& filename, const std::string& targetWord, const std::string& substringToRemove) {
	
	std::ifstream inputFile(filename);
	std::istream_iterator<std::string> fileIterator(inputFile);
	std::istream_iterator<std::string> eof;

	std::vector<std::string> words(fileIterator, eof);

	// 2. pojavljivanje
	std::vector<size_t> positions;
	auto it = std::find(words.begin(), words.end(), targetWord);
	while (it != words.end()) {
		positions.push_back(std::distance(words.begin(), it));
		it = std::find(++it, words.end(), targetWord);
	}

	// 3. podstring
	words.erase(std::remove_if(words.begin(), words.end(), [substringToRemove](const std::string& str) {
		return str.find(substringToRemove) != std::string::npos;
	}), words.end());

	// 4. velika slova
	std::transform(words.begin(), words.end(), words.begin(), [](std::string& str) {
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		return str;
	});

	
	std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

int main2() {
	const std::string filename = "words.txt";
	const std::string targetWord = "example";
	const std::string substringToRemove = "substring";

	processFile(filename, targetWord, substringToRemove);

	return 0;
}
