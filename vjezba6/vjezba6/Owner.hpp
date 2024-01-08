#ifndef OWNER_H
#define OWNER_H

#include <vector>
#include "VirtualPet.h"

class Owner {
public:
	Owner(const std::string& ime);
	Owner(const Owner& drugi); // Copy konstruktor
	Owner(Owner&& drugi) noexcept; // Move konstruktor
	~Owner();

	void dodajLjubimca(const std::string& ime, const std::string& vrsta);
	void interagirajSLjubimcima();

	void ispisiStanjeLjubimaca() const;

private:
	std::string ime;
	std::vector<VirtualPet> ljubimci;
};

#endif // OWNER_H


