#include "Owner.h"
#include "VirtualPet.h"
#include <iostream>

int main() {
	// Kreiranje vlasnika
	Owner vlasnik("John");

	// Dodavanje ljubimaca vlasniku
	vlasnik.dodajLjubimca("Buddy", "Pas");
	vlasnik.dodajLjubimca("Whiskers", "Mačka");
	vlasnik.dodajLjubimca("Fluffy", "Zec");

	// Interakcija s ljubimcima
	vlasnik.interagirajSLjubimcima();

	// Ispisivanje trenutnog stanja ljubimaca
	vlasnik.ispisiStanjeLjubimaca();

	return 0;
}