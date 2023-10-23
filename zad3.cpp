#include <iostream>
#include <iomanip>

struct Matrix {
	int rows;
	int cols;
	float** data;

	// Funkcija za unos matrice
	void inputMatrix() {
		std::cout << "Unesite broj redaka (m): ";
		std::cin >> rows;
		std::cout << "Unesite broj stupaca (n): ";
		std::cin >> cols;

		data = new float*[rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new float[cols];
			for (int j = 0; j < cols; j++) {
				std::cout << "Unesite element [" << i << "][" << j << "]: ";
				std::cin >> data[i][j];
			}
		}
	}

	// Funkcija za generiranje matrice mxn s elementima u rasponu [a, b]
	void generateMatrix(int m, int n, float a, float b) {
		rows = m;
		cols = n;

		data = new float*[rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new float[cols];
			for (int j = 0; j < cols; j++) {
				data[i][j] = a + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (b - a)));
			}
		}
	}

	// Funkcija za zbrajanje matrica
	Matrix addMatrix(const Matrix& other) {
		Matrix result;
		result.rows = rows;
		result.cols = cols;
		result.data = new float*[result.rows];
		for (int i = 0; i < result.rows; i++) {
			result.data[i] = new float[result.cols];
			for (int j = 0; j < result.cols; j++) {
				result.data[i][j] = data[i][j] + other.data[i][j];
			}
		}
		return result;
	}

	// Funkcija za oduzimanje matrica
	Matrix subtractMatrix(const Matrix& other) {
		Matrix result;
		result.rows = rows;
		result.cols = cols;
		result.data = new float*[result.rows];
		for (int i = 0; i < result.rows; i++) {
			result.data[i] = new float[result.cols];
			for (int j = 0; j < result.cols; j++) {
				result.data[i][j] = data[i][j] - other.data[i][j];
			}
		}
		return result;
	}

	// Funkcija za množenje matrica
	Matrix multiplyMatrix(const Matrix& other) {
		if (cols != other.rows) {
			std::cerr << "Matrice nisu pogodne za množenje." << std::endl;
			Matrix empty;
			return empty;
		}

		Matrix result;
		result.rows = rows;
		result.cols = other.cols;
		result.data = new float*[result.rows];
		for (int i = 0; i < result.rows; i++) {
			result.data[i] = new float[result.cols];
			for (int j = 0; j < result.cols; j++) {
				result.data[i][j] = 0.0;
				for (int k = 0; k < cols; k++) {
					result.data[i][j] += data[i][k] * other.data[k][j];
				}
			}
		}
		return result;
	}

	// Funkcija za transponiranje matrice
	Matrix transposeMatrix() {
		Matrix result;
		result.rows = cols;
		result.cols = rows;
		result.data = new float*[result.rows];
		for (int i = 0; i < result.rows; i++) {
			result.data[i] = new float[result.cols];
			for (int j = 0; j < result.cols; j++) {
				result.data[i][j] = data[j][i];
			}
		}
		return result;
	}

	// Funkcija za ispisivanje matrice
	void printMatrix() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				std::cout << std::fixed << std::setprecision(4) << data[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	// Funkcija za brisanje matrice
	void deleteMatrix() {
		for (int i = 0; i < rows; i++) {
			delete[] data[i];
		}
		delete[] data;
		data = nullptr;
		rows = 0;
		cols = 0;
	}
};

int main() {
	Matrix A, B;
	A.inputMatrix();
	B.inputMatrix();

	std::cout << "Matrica A:" << std::endl;
	A.printMatrix();

	std::cout << "Matrica B:" << std::
