#include "Vector.h"
#include <iostream>
#include <string>
#include <sstream>

//***************************************************************************
//Function:    addElement
//
//Description: Adds an elements to the vector row
//
//Parameters:	 int - the element to add, will be converted to rational / 1
//
//Returned:    None
//***************************************************************************
void Vector::addElement(int element){
	mvElements.push_back(Rational(element, 1));
}

//***************************************************************************
//Function:    print
//
//Description: Prints the vector to a stream
//
//Parameters:	 out - the ostream to print to
//
//Returned:    None
//***************************************************************************
void Vector::print(std::ostream& out) {
	out << "| ";
	for (int i = 0; i < size(); i++) {
		out << std::left << mvElements[i] << " ";
	}
	out << "|\n";
}

//***************************************************************************
//Function:    size
//
//Description: returns the size of the vector
//
//Parameters:	 None
//
//Returned:    int - the size of the vector
//***************************************************************************
int Vector::size() {
	return (int) mvElements.size();
}

//***************************************************************************
//Function:    getElement
//
//Description: returns the rational at the given index
//
//Parameters:	 index - an integer containing the index of the desired element
//
//Returned:    Rational - the rational at the given index
//***************************************************************************
Rational& Vector::getElement(int index) {
	return mvElements[index];
}

//***************************************************************************
//Function:    simplify
//
//Description: Finds the first pivot in the row, and multiplies the row
//						 by a rational to make this pivot a 1
//
//Parameters:	 None
//
//Returned:    Rational - the rational multiplied by
//***************************************************************************
Rational Vector::simplify() {
	Rational cInverse;

	for (int i = 0; i < size(); i++) {
		if (!mvElements.at(i).isZero()) {
			cInverse = mvElements.at(i).getInverse();
			for (int j = i; j < size(); j++) {
				mvElements.at(j) *= cInverse;
			}
			i = mvElements.size();
		}
	}

	return cInverse;
}

//***************************************************************************
//Function:    operator>>
//
//Description: Reads into the Vector from an istream
//
//Parameters:	 in     - the istream to read from
//						 vector - the vector to read into
//
//Returned:    istream - the istream that was read from
//***************************************************************************
std::istream& operator>>(std::istream& in, Vector& vector) {
	std::string input;
	std::getline(in, input);
	std::istringstream stringStream(input);
	int value;

	while (stringStream >> value) {
		vector.addElement(value);
	}

	return in;
}