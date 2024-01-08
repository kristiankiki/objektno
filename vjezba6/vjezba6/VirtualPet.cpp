#include "VirtualPet.h"
#include <iostream>

VirtualPet::VirtualPet(const std::string& ime, const std::string& vrsta)
	: ime(ime), vrsta(vrsta), glad(0), sreca(0), budan(true) {}

VirtualPet::VirtualPet(const VirtualPet& drugi)
	: ime(drugi.ime + "_kopija"), vrsta(drugi.vrsta), glad(drugi.glad), sreca(drugi.sreca), budan(drugi.budan) {
	std::cout << "Copy konstruktor pozvan za " << drugi.ime << std::endl;
}

VirtualPet::VirtualPet(VirtualPet&& drugi) noexcept
	: ime(std::move(drugi.ime)), vrsta(std::move(drugi.vrsta)), glad(drugi.glad), sreca(drugi.sreca), budan(drugi.budan) {
	drugi.glad = 0;
	drugi.sreca = 0;
	drugi.budan = true;
	std::cout << "Move konstruktor pozvan za " << ime << std::endl;
}

VirtualPet::~VirtualPet() {
	std::cout << "Destruktor pozvan za " << ime << std::endl;
}

void VirtualPet::jede() {
	glad -= 5;
	sreca += 10;
}

void VirtualPet::spava() {
	if (glad >= 10) {
		glad += 5;
		sreca += 10;
		budan = false;
	}
	else {
		std::cout << "Nema dovoljno gladi za spavanje!" << std::endl;
	}
}

void VirtualPet::igra() {
	glad += 5;
	sreca += 15;
}

void VirtualPet::ispisiStanje() const {
	std::cout << "Ljubimac: " << ime << " | Vrsta: " << vrsta << " | Glad: " << glad
		<< " | Sreca: " << sreca << " | Budan: " << (budan ? "Da" : "Ne") << std::endl;
}
