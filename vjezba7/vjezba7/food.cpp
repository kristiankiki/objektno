#include <iostream>

class Food {
private:
	static int counter; // Privatni statički član koji broji raspoložive porcije hrane

public:
	Food() {
		counter++; // Povećava broj raspoloživih porcija pri svakom stvaranju objekta Food
	}

	~Food() {
		counter--; // Smanjuje broj raspoloživih porcija pri uništavanju objekta Food
	}

	static void changeCounter(int value) {
		counter += value; // Mijenja vrijednost counter-a
	}

	static void printCounter() {
		std::cout << "Broj raspoloživih porcija hrane: " << counter << std::endl;
	}

	friend int get_counter(); // Prijateljska deklaracija non-member funkcije get_counter
};

// Definicija privatnog statičkog člana counter
int Food::counter = 0;

// Non-member funkcija get_counter koja vraća vrijednost counter-a
int get_counter() {
	return Food::counter;
}

int main() {
	Food food1; // Stvaranje jedne porcije hrane
	Food::printCounter(); // Ispis trenutnog broja raspoloživih porcija hrane

	{
		Food food2; // Stvaranje druge porcije hrane u novom opsegu
		Food::printCounter(); // Ispis trenutnog broja raspoloživih porcija hrane unutar novog opsega
	}

	Food::printCounter(); // Ispis trenutnog broja raspoloživih porcija hrane nakon završetka opsega s food2

	Food::changeCounter(5); // Povećavanje broja raspoloživih porcija za 5
	Food::printCounter(); // Ispis trenutnog broja raspoloživih porcija hrane nakon povećanja

	std::cout << "Vrijednost counter-a izvan klase: " << get_counter() << std::endl; // Korištenje non-member funkcije get_counter

	return 0;
}