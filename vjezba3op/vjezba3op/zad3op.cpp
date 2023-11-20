#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> vec = { 5, 8, 2, 10, 3, 1, 6 };

	
	std::sort(vec.begin(), vec.end());

	
	int minElement = *std::min_element(vec.begin(), vec.end());

	
	auto it = vec.begin();
	while ((it = std::find(it, vec.end(), minElement)) != vec.end()) {
		vec.insert(it, 0);
		it = std::next(it, 2); // Pomakni pokazivač za dva koraka
	}

	
	int maxElement = *std::max_element(vec.begin(), vec.end());

	
	int sum = 0;
	bool afterMax = false;

	for (int element : vec) {
		if (afterMax) {
			sum += element;
		}

		if (element == maxElement) {
			afterMax = true;
		}
	}

	
	std::cout << "Sortirani vektor sa 0 ispred najmanjih elemenata:" << std::endl;
	for (int element : vec) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	std::cout << "Najveći element: " << maxElement << std::endl;
	std::cout << "Suma svih elemenata iza najvećeg elementa: " << sum << std::endl;

	return 0;
}
