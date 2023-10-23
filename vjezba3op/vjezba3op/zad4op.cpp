#include <iostream>
#include <vector>
#include <algorithm>

void removeElement(std::vector<int>& vec, int target) {
	vec.erase(std::remove(vec.begin(), vec.end(), target), vec.end());
}

int main() {
	std::vector<int> vec = { 5, 8, 2, 10, 3, 1, 6 };

	int target = 3;

	removeElement(vec, target);

	std::cout << "Vektor nakon uklanjanja elementa " << target << ":" << std::endl;
	for (int element : vec) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	return 0;
}
