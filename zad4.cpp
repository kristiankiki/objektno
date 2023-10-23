#include <iostream>

struct Vector {
	int* elements;       // Niz elemenata
	int logicalSize;     // Logička veličina vektora (broj elemenata)
	int physicalSize;    // Fizička veličina vektora (trenutni kapacitet)

	// Funkcija za stvaranje novog vektora
	void vector_new() {
		elements = nullptr;
		logicalSize = 0;
		physicalSize = 0;
	}

	// Funkcija za brisanje vektora
	void vector_delete() {
		delete[] elements;
		elements = nullptr;
		logicalSize = 0;
		physicalSize = 0;
	}

	// Funkcija za dodavanje elementa na kraj vektora
	void vector_push_back(int value) {
		if (logicalSize == physicalSize) {
			// Ako je fizička veličina popunjena, alociraj duplo
			physicalSize = (physicalSize == 0) ? 1 : 2 * physicalSize;
			int* newElements = new int[physicalSize];
			for (int i = 0; i < logicalSize; i++) {
				newElements[i] = elements[i];
			}
			delete[] elements;
			elements = newElements;
		}
		elements[logicalSize] = value;
		logicalSize++;
	}

	// Funkcija za uklanjanje elementa s kraja vektora
	void vector_pop_back() {
		if (logicalSize > 0) {
			logicalSize--;
		}
	}

	// Funkcija za pristup prvom elementu
	int vector_front() {
		if (logicalSize > 0) {
			return elements[0];
		}
		else {
			std::cerr << "Vektor je prazan." << std::endl;
			return -1; // Vraća se neka podrazumijevana vrijednost ako je vektor prazan
		}
	}

	// Funkcija za pristup posljednjem elementu
	int vector_back() {
		if (logicalSize > 0) {
			return elements[logicalSize - 1];
		}
		else {
			std::cerr << "Vektor je prazan." << std::endl;
			return -1; // Vraća se neka podrazumijevana vrijednost ako je vektor prazan
		}
	}

	// Funkcija za dobivanje trenutne veličine vektora
	int vector_size() {
		return logicalSize;
	}
};

int main() {
	Vector vec;
	vec.vector_new();

	vec.vector_push_back(5);
	vec.vector_push_back(8);
	vec.vector_push_back(2);
	vec.vector_push_back(10);
	vec.vector_push_back(3);

	std::cout << "Prvi element: " << vec.vector_front() << std::endl;
	std::cout << "Zadnji element: " << vec.vector_back() << std::endl;
	std::cout << "Veličina vektora: " << vec.vector_size() << std::endl;

	vec.vector_pop_back();
	std::cout << "Nakon uklanjanja posljednjeg elementa, veličina vektora: " << vec.vector_size() << std::endl;

	vec.vector_delete();

	return 0;
}
