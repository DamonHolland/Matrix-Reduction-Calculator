#include "Vector.h"
#include <iostream>
#include <string>
#include <sstream>

void Vector::addElement(double element){
	mvElements.push_back(element);
}

void Vector::print(std::ostream& out) {
	out << "[ ";
	for (int i = 0; i < mvElements.size(); i++) {
		out << mvElements.at(i) << " ";
	}
	out << "]\n";
}

int Vector::simplify() {
	int pivotIndex = -1, pivotValue = 0;

	for (int i = 0; i < mvElements.size(); i++) {
		if (mvElements.at(i) != 0) {
			pivotIndex = i;
			pivotValue = mvElements.at(i);
			i = mvElements.size();
		}
	}

	if (pivotIndex != -1){
		for (int i = pivotIndex; i < mvElements.size(); i++) {
			mvElements.at(i) /= pivotValue;
		}
	}

	return pivotValue;
}

std::istream& operator>>(std::istream& in, Vector& vector) {
	std::string input;
	std::getline(in, input);
	std::istringstream stringStream(input);
	double value;

	while (stringStream >> value) {
		vector.addElement(value);
	}

	return in;
}