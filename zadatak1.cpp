#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

// Enum za znak karte
enum Znak {
	HERC,
	KARO,
	PIK,
	TREF
};

// Struktura za kartu
struct Karta {
	int broj;
	Znak znak;
};

// Klasa za mac (deck)
class Mac {
private:
	std::vector<Karta> karte;

public:
	Mac() {
		// Inicijalizacija karata u macu
		for (int broj = 1; broj <= 10; ++broj) {
			for (int znak = HERC; znak <= TREF; ++znak) {
				Karta novaKarta = { broj, static_cast<Znak>(znak) };
				karte.push_back(novaKarta);
			}
		}
		// Mijesanje karata
		std::random_shuffle(karte.begin(), karte.end());
	}

	// Metoda za podjelu karata igracima
	std::vector<Karta> podijeliKarte(int brojIgraca, int indexIgraca) {
		std::vector<Karta> karteIgraca;

		// Provjeri broj igraca i podijeli karte
		if (brojIgraca == 2 || brojIgraca == 4) {
			for (int i = indexIgraca * 10; i < (indexIgraca + 1) * 10; ++i) {
				karteIgraca.push_back(karte[i]);
			}
		}

		return karteIgraca;
	}
};

// Klasa za igraca
class Igrac {
private:
	std::string ime;
	std::vector<Karta> kombinacijaKarata;
	int bodovi;

public:
	Igrac(std::string ime) : ime(ime), bodovi(0) {}

	// Metoda za dodavanje karte u kombinaciju
	void dodajKartu(Karta karta) {
		kombinacijaKarata.push_back(karta);
	}

	// Metoda za izracunavanje bodova iz akuze
	int izracunajBodoveIzAkuze() {
		int bodoviAkuza = 0;
		// Implementacija pravila za akuze
		// ...

		return bodoviAkuza;
	}

	// Metoda za ispis informacija o igracu
	void ispisiInfo() {
		std::cout << "Igrac: " << ime << ", Bodovi iz akuze: " << izracunajBodoveIzAkuze() << std::endl;
	}
};

int main() {
	// Postavljanje seed-a za generiranje pseudo-slučajnih brojeva
	std::srand(std::time(0));

	int brojIgraca;
	std::cout << "Unesite broj igraca (2 ili 4): ";
	std::cin >> brojIgraca;

	if (brojIgraca != 2 && brojIgraca != 4) {
		std::cout << "Neispravan broj igraca. Program zavrsava." << std::endl;
		return 1;
	}

	std::vector<Igrac> igraci;
	for (int i = 0; i < brojIgraca; ++i) {
		std::string ime;
		std::cout << "Unesite ime igraca " << i + 1 << ": ";
		std::cin >> ime;
		igraci.push_back(Igrac(ime));
	}

	Mac mac;

	for (int i = 0; i < brojIgraca; ++i) {
		std::vector<Karta> karteIgraca = mac.podijeliKarte(brojIgraca, i);
		for (const auto& karta : karteIgraca) {
			igraci[i].dodajKartu(karta);
		}
	}

	for (const auto& igrac : igraci) {
		igrac.ispisiInfo();
	}

	return 0;
}
