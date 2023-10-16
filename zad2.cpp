#include <iostream>


int& GetAndIncrement(int* arr, int index) {
	return arr[index];
}

int main() {
	int n = 5; 
	int* arr = new int[n];

	
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}

	int index = 2; 
	std::cout << "Pre uvecavanja: arr[" << index << "] = " << arr[index] << std::endl;

	
	GetAndIncrement(arr, index)++; 

	std::cout << "Nakon uvecavanja: arr[" << index << "] = " << arr[index] << std::endl;

	delete[] arr; 
	return 0;
}
