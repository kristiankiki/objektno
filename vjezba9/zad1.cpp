#include <iostream>
#include <string>

template <typename T>
T min(T a, T b) {
	return (a < b) ? a : b;
}

int main() {
	// Testiranje sa brojevima
	int num1 = 5, num2 = 3;
	std::cout << "Minimum number: " << min(num1, num2) << std::endl;

	// Testiranje sa stringovima
	std::string str1 = "apple", str2 = "orange";
	std::cout << "Minimum string: " << min(str1, str2) << std::endl;

	return 0;
}