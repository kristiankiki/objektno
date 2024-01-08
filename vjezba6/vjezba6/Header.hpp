#ifndef VIRTUALPET_H
#define VIRTUALPET_H

#include <string>

class VirtualPet {
public:
	VirtualPet(const std::string& ime, const std::string& vrsta);
	VirtualPet(const VirtualPet& drugi); // Copy konstruktor
	VirtualPet(VirtualPet&& drugi) noexcept; // Move konstruktor
	~VirtualPet();

	void jede();
	void spava();
	void igra();

	void ispisiStanje() const;

private:
	std::string ime;
	std::string vrsta;
	int glad;
	int sreca;
	bool budan;
};

#endif // VIRTUALPET_H