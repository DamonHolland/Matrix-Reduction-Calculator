#include "Matrix.h"

//***************************************************************************
//Function:    addVector
//
//Description: adds a new vector to the matrix
//
//Parameters:	 vector - the vector to add
//
//Returned:    None
//***************************************************************************
void Matrix::addVector(Vector vector) {
	mvVectors.push_back(vector);
}

//***************************************************************************
//Function:    print
//
//Description: prints the matrix to a stream
//
//Parameters:	 out - the ostream to print to
//
//Returned:    None
//***************************************************************************
void Matrix::print(std::ostream& out) {
	for (int i = 0; i < (int) mvVectors.size(); i++) {
		mvVectors.at(i).print(out);
	}
}

//***************************************************************************
//Function:    simplifyRows
//
//Description: simplifies all the rows in the matrix
//
//Parameters:	 out - the ostream to print to, used to show steps
//
//Returned:    None
//***************************************************************************
void Matrix::simplifyRows(std::ostream& out) {
	Rational inverse(0, 0);
	for (int i = 0; i < (int) mvVectors.size(); i++) {
		inverse = simplifyRow(i);
		if (inverse.getNum() != inverse.getDen()) { 
			out << "R" << i + 1 << " = " << inverse << "R" << i + 1;
			out << std::endl;
			print(out);
			out << std::endl;
		}
	}
}

//***************************************************************************
//Function:    simplifyRow
//
//Description: simplifies the given row in the matrix
//
//Parameters:	 row - an int containint the row to simplify
//
//Returned:    Rational - the rational used as a row operation
//***************************************************************************
Rational Matrix::simplifyRow(int row) {
	return mvVectors.at(row).simplify();
}