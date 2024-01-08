#include <iostream>
#include <string>

class VirtualPet {
public:
	// Konstruktor
	VirtualPet(const std::string& ime, const std::string& vrsta)
		: ime(ime), vrsta(vrsta), glad(0), sreca(0), budan(true) {}

	// ... (ostale metode i članovi)

	// Operator ==
	bool operator==(const VirtualPet& other) const {
		return (ime == other.ime) && (vrsta == other.vrsta) &&
			(glad == other.glad) && (sreca == other.sreca) && (budan == other.budan);
	}

	// Operator !=
	bool operator!=(const VirtualPet& other) const {
		return !(*this == other);
	}

	// Operator =
	VirtualPet& operator=(const VirtualPet& other) {
		if (this != &other) {
			ime = other.ime;
			vrsta = other.vrsta;
			glad = other.glad;
			sreca = other.sreca;
			budan = other.budan;
		}
		return *this;
	}

	// Operator ++
	VirtualPet& operator++() {  // Prefiksni inkrement
		glad -= 5;
		sreca += 10;
		return *this;
	}

	VirtualPet operator++(int) {  // Postfiksni inkrement
		VirtualPet temp = *this;
		glad -= 5;
		sreca += 10;
		return temp;
	}

	// Operator <, >, <=, >= relacije sreće
	bool operator<(const VirtualPet& other) const {
		return sreca < other.sreca;
	}

	bool operator>(const VirtualPet& other) const {
		return sreca > other.sreca;
	}

	bool operator<=(const VirtualPet& other) const {
		return sreca <= other.sreca;
	}

	bool operator>=(const VirtualPet& other) const {
		return sreca >= other.sreca;
	}

	// Operator <<
	friend std::ostream& operator<<(std::ostream& os, const VirtualPet& ljubimac) {
		os << "Ime: " << ljubimac.ime << " | Vrsta: " << ljubimac.vrsta
			<< " | Glad: " << ljubimac.glad << " | Sreca: " << ljubimac.sreca
			<< " | Budan: " << (ljubimac.budan ? "Da" : "Ne");
		return os;
	}

private:
	std::string ime;
	std::string vrsta;
	int glad;
	int sreca;
	bool budan;
};

int main() {
	VirtualPet ljubimac1("Buddy", "Pas");
	VirtualPet ljubimac2("Mittens", "Mačka");

	// Testiranje operatora ==
	if (ljubimac1 == ljubimac2) {
		std::cout << "Ljubimci su jednaki." << std::endl;
	}
	else {
		std::cout << "Ljubimci nisu jednaki." << std::endl;
	}

	// Testiranje operatora !=
	if (ljubimac1 != ljubimac2) {
		std::cout << "Ljubimci su različiti." << std::endl;
	}
	else {
		std::cout << "Ljubimci nisu različiti." << std::endl;
	}

	// Testiranje operatora =
	VirtualPet ljubimac3("Rex", "Pas");
	ljubimac3 = ljubimac1;
	std::cout << "Ljubimac 3: " << ljubimac3 << std::endl;

	// Testiranje operatora ++
	std::cout << "Prije inkrementa: " << ljubimac1 << std::endl;
	++ljubimac1;
	std::cout << "Nakon prefiksnog inkrementa: " << ljubimac1 << std::endl;
	VirtualPet ljubimac4 = ljubimac2++;
	std::cout << "Nakon postfiksnog inkrementa: " << ljubimac2 << std::endl;
	std::cout << "Nakon postfiksnog inkrementa (rezultat): " << ljubimac4 << std::endl;

	// Testiranje relacijskih operatora
	if (ljubimac1 < ljubimac2) {
		std::cout << "Ljubimac 1 je manje sretan od ljubimca 2." << std::endl;
	}
	else {
		std::cout << "Ljubimac 1 nije manje sretan od ljubimca 2." << std::endl;
	}

	return 0;
}