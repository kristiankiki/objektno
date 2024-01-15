#include <iostream>
#include <algorithm>

template <typename T>
class Skup {
private:
	T* elementi;
	int kapacitet;
	int velicina;

public:
	Skup(int pocetniKapacitet = 10) : kapacitet(pocetniKapacitet), velicina(0) {
		elementi = new T[kapacitet];
	}

	~Skup() {
		delete[] elementi;
	}

	void dodajElement(const T& element) {
		if (!sadrziElement(element)) {
			if (velicina == kapacitet) {
				proširiSkup();
			}
			elementi[velicina++] = element;
		}
	}

	void izbaciElement(const T& element) {
		auto it = std::find(elementi, elementi + velicina, element);
		if (it != elementi + velicina) {
			std::swap(*it, elementi[--velicina]);
		}
	}

	bool sadrziElement(const T& element) const {
		return std::find(elementi, elementi + velicina, element) != elementi + velicina;
	}

	void ispisiSkup() const {
		std::cout << "Skup: { ";
		for (int i = 0; i < velicina; ++i) {
			std::cout << elementi[i] << " ";
		}
		std::cout << "}\n";
	}

private:
	void proširiSkup() {
		int noviKapacitet = kapacitet * 2;
		T* noviElementi = new T[noviKapacitet];
		std::copy(elementi, elementi + velicina, noviElementi);
		delete[] elementi;
		elementi = noviElementi;
		kapacitet = noviKapacitet;
	}
};

int main() {
	Skup<int> integerSkup;

	integerSkup.dodajElement(5);
	integerSkup.dodajElement(10);
	integerSkup.dodajElement(5);
	integerSkup.dodajElement(15);

	integerSkup.ispisiSkup();

	integerSkup.izbaciElement(10);
	integerSkup.ispisiSkup();

	std::cout << "Je li 5 u skupu? " << (integerSkup.sadrziElement(5) ? "Da" : "Ne") << std::endl;

	return 0;
}