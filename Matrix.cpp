#include "Matrix.h"

void Matrix::addVector(Vector vector) {
	mvVectors.push_back(vector);
}


void Matrix::print(std::ostream& out) {
	for (int i = 0; i < mvVectors.size(); i++) {
		mvVectors.at(i).print(out);
	}
}

void Matrix::simplifyRows(std::ostream& out) {
	int divisor;
	for (int i = 0; i < mvVectors.size(); i++) {
		divisor = simplifyRow(i);
		if (divisor != 0) { 
			out << "R" << i + 1 << " = " << "R" << i + 1 << "/" << divisor;
			out << std::endl;
			print(out);
			out << std::endl;
		}
	}
}

int Matrix::simplifyRow(int row) {
	return mvVectors.at(row).simplify();
}