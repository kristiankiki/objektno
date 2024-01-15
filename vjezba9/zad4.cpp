#include <iostream>
#include <cmath>

template <typename T>
class point {
public:
	T x, y;

	point(T x, T y) : x(x), y(y) {}

	// Operator overload for subtraction
	T operator-(const point& other) const {
		T dx = x - other.x;
		T dy = y - other.y;
		return std::sqrt(dx * dx + dy * dy);
	}

	// Operator overload for output stream
	friend std::ostream& operator<<(std::ostream& os, const point& p) {
		os << "(" << p.x << "," << p.y << ")";
		return os;
	}
};

int main() {
	point<int> p1(2, 3), p2(3, 4);
	std::cout << "Udaljenost tocaka " << p1 << " i " << p2 << " je " << p1 - p2 << std::endl;

	return 0;
}
