#include <iostream>
#include <algorithm>

template <typename T>
void customSort(T arr[], int size) {
	std::sort(arr, arr + size);
}

// Specijalizacija za nizove karaktera
template <>
void customSort<char>(char arr[], int size) {
	std::sort(arr, arr + size, [](char a, char b) {
		return std::tolower(a) < std::tolower(b);
	});
}

int main() {
	// Primer sa običnim nizom
	int intArray[] = { 4, 2, 7, 1, 5 };
	int intSize = sizeof(intArray) / sizeof(int);
	customSort(intArray, intSize);

	std::cout << "Sorted int array: ";
	for (int i = 0; i < intSize; i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	// Primer sa nizom karaktera
	char charArray[] = { 'd', 'B', 'a', 'C', 'f' };
	int charSize = sizeof(charArray) / sizeof(char);
	customSort(charArray, charSize);

	std::cout << "Sorted char array (case-insensitive): ";
	for (int i = 0; i < charSize; i++) {
		std::cout << charArray[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
