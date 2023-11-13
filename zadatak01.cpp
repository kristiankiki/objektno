#include <iostream>
#include <string>

int brojPojavljivanjaPodstringa(const std::string& str, const std::string& podstring) {
	int brojac = 0;
	size_t pozicija = str.find(podstring);  

	while (pozicija != std::string::npos) {
		brojac++;  
		pozicija = str.find(podstring, pozicija + 1);  
	}

	return brojac;
}

int main() {
	std::string str = "primjer,primjer,primjer,primjer.";
	std::string podstring = "primjer";

	int pojave = brojPojavljivanjaPodstringa(str, podstring);

	std::cout << "Podstring \"" << podstring << "\" se pojavljuje " << pojave << " puta u stringu." << std::endl;

	return 0;
}