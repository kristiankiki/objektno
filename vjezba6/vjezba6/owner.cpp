#include "Owner.h"
#include <iostream>
#include <algorithm>
#include <random>

Owner::Owner(const std::string& ime) : ime(ime) {}

Owner::Owner(const Owner& drugi) : ime(drugi.ime + "_kopija"), ljubimci(drugi.ljubimci) {
	std::cout << "Copy konstruktor pozvan za " << drugi.ime << std::endl;
}

Owner::Owner(Owner&& drugi) noexcept : ime(std::move(drugi.ime)), ljubimci(std::move(drugi.ljubimci)) {
	std::cout << "Move konstruktor pozvan za " << ime << std::endl;
}

Owner::~Owner() {
	std::cout << "Destruktor pozvan za " << ime << std::endl;
}

void Owner::dodajLjubimca(const std::string& ime, const std::string& vrsta) {
	ljubimci.emplace_back(ime, vrsta);
}

void Owner::interagirajSLjubimcima() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(ljubimci.begin(), ljubimci.end(), g);

	for (auto& ljubimac : ljubimci) {
		int akcija = rand() % 3;
		switch (akcija) {
		case 0:
			ljubimac.jede();
			break;
		case 1:
			ljubimac.spava();
			break;
		case 2:
			ljubimac.igra();
			break;
		default:
			break;
		}
	}
}

void Owner::ispisiStanjeLjubimaca() const {
	std::cout << "Vlasnik: " << ime << std::endl;
	for (const auto& ljubimac : ljubimci) {
		ljubimac.ispisiStanje();
	}
}