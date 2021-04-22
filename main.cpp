#include <iostream>
#include "Vector.h"
#include "Matrix.h"

int main() {
	int numRows;
	Matrix theMatrix;

	std::cout << "Enter the number of rows: ";
	std::cin >> numRows;
	std::cout << std::endl;
	std::cin.ignore();

	for (int i = 0; i < numRows; i++) {
		Vector newVector;
		std::cout << "Enter row " << i + 1 << ": ";
		std::cin >> newVector;
		theMatrix.addVector(newVector);
	}

	std::cout << std::endl;

	theMatrix.simplifyRows(std::cout);

	return EXIT_SUCCESS;
}