#include <iostream>

void pronadjiNajveciINajmanji(int* niz, int n, int& najmanji, int& najveci) {
	if (n == 0) {
		
		najmanji = najveci = 0;
		return;
	}

	
	najmanji = najveci = niz[0];

	for (int i = 1; i < n; i++) {
		if (niz[i] < najmanji) {
			najmanji = niz[i];
		}
		if (niz[i] > najveci) {
			najveci = niz[i];
		}
	}
}

int main2() {
	int n;
	std::cout << "Unesite broj elemenata niza: ";
	std::cin >> n;

	if (n <= 0) {
		std::cout << "Niz mora sadržavati barem jedan element." << std::endl;
		return 1;
	}

	int* niz = new int[n]; 

	std::cout << "Unesite " << n << " prirodnih brojeva: ";
	for (int i = 0; i < n; i++) {
		std::cin >> niz[i];
	}

	int najmanji, najveci;
	pronadjiNajveciINajmanji(niz, n, najmanji, najveci);

	std::cout << "Najmanji broj u nizu: " << najmanji << std::endl;
	std::cout << "Najveci broj u nizu: " << najveci << std::endl;

	delete[] niz; 

	return 0;
}
