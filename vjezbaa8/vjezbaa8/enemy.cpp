class Enemy {
public:
	Enemy(const std::string& ime, int zdravlje, int steta) : ime(ime) {
		if (zdravlje < 0 || steta < 0) {
			throw std::invalid_argument("Zdravlje i steta moraju biti nenegativni");
		}
		this->zdravlje = zdravlje;
		this->steta = steta;
	}

	virtual ~Enemy() {}

	virtual void napad() const = 0;
	virtual void prikaziInfo() const = 0;

protected:
	std::string ime;
	int zdravlje;
	int steta;
};




class Boss : public Enemy {
public:
	Boss(const std::string& ime, int zdravlje, int steta, const std::string& oruzje) : Enemy(ime, zdravlje, steta) {
		if (oruzje.empty()) {
			throw std::invalid_argument("Oružje ne smije biti prazno");
		}
		this->oruzje = oruzje;
	}

	void napad() const override {
		std::cout << "Šef napada sa " << oruzje << " i nanosi " << steta << " štete." << std::endl;
	}

	void prikaziInfo() const override {
		std::cout << "Šef: " << ime << ", Zdravlje: " << zdravlje << ", Šteta: " << steta << ", Oružje: " << oruzje << std::endl;
	}

private:
	std::string oruzje;
};






class Monster : public Enemy {
public:
	Monster(const std::string& ime, int zdravlje, int steta, const std::string& sposobnost) : Enemy(ime, zdravlje, steta) {
		if (sposobnost.empty()) {
			throw std::invalid_argument("Sposobnost ne smije biti prazna");
		}
		this->sposobnost = sposobnost;
	}

	void napad() const override {
		std::cout << "Čudovište napada sa " << sposobnost << " i nanosi " << steta << " štete." << std::endl;
	}

	void prikaziInfo() const override {
		std::cout << "Čudovište: " << ime << ", Zdravlje: " << zdravlje << ", Šteta: " << steta << ", Sposobnost: " << sposobnost << std::endl;
	}

private:
	std::string sposobnost;
};


GLAVNA


int main() {
	std::vector<Enemy*> neprijatelji;

	try {
		neprijatelji.push_back(new Boss("Zli šef", 100, 20, "Mač"));
		neprijatelji.push_back(new Monster("Strašno čudovište", 80, 15, "Vatreni dah"));
		neprijatelji.push_back(new Boss("Još jedan šef", -50, 25, "Sjekira")); // Nevaljano zdravlje, trebalo bi izazvati iznimku
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Greška: " << e.what() << std::endl;
	}

	for (const auto& neprijatelj : neprijatelji) {
		neprijatelj->prikaziInfo();
		neprijatelj->napad();
		std::cout << "-----------------------" << std::endl;
	}

	// Čišćenje
	for (const auto& neprijatelj : neprijatelji) {
		delete neprijatelj;
	}

	return 0;
}