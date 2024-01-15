#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <string>

struct Point {
	double x;
	double y;
};

//   izračun udaljenosti 
double distanceFromOrigin(const Point& p) {
	return std::sqrt(p.x * p.x + p.y * p.y);
}

int main() {
	
	std::ifstream inputFile("points.txt");
	std::istream_iterator<Point> inputIterator(inputFile);
	std::istream_iterator<Point> endIterator;

	std::vector<Point> points(inputIterator, endIterator);

	// 2. Sortiranje
	std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
		return distanceFromOrigin(a) < distanceFromOrigin(b);
	});

	// 3. Prebroji točke unutar određenog kruga
	double radius = 5.0;  
	int countWithinRadius = std::count_if(points.begin(), points.end(), [radius](const Point& p) {
		return distanceFromOrigin(p) < radius;
	});

	// 4. Zamjena
	double targetDistance = 3.0;  
	std::replace_if(points.begin(), points.end(), [targetDistance](const Point& p) {
		return std::abs(distanceFromOrigin(p) - targetDistance) < 1e-6;
	}, Point{ 10.0, 10.0 });  

	
	std::reverse(points.begin(), points.end());
	std::copy(points.begin(), points.end(), std::ostream_iterator<Point>(std::cout, "\n"));

	return 0;
}
