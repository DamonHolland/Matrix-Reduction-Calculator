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
//Function:    reduce
//
//Description: Reduces the matrix to row echelon form, if possible
//
//Parameters:	 out - the ostream to print steps taken
//
//Returned:    None
//***************************************************************************
void Matrix::reduce(std::ostream& out) { 
	int currCol = 0, currRow = 0;
	Rational currElement(0, 0);
	bool bFoundNonZero;
	int nonZeroRow = 0;

	print(out);

	while (currCol < (int) mvVectors.size()) {
		bFoundNonZero = false;
		while (currRow < mvVectors.at(currCol).size()) {
			currElement = mvVectors.at(currRow).getElement(currCol);
			if (!bFoundNonZero) {
				if (currElement.getNum() != 0) {
					bFoundNonZero = true;
					nonZeroRow = currRow;
					simplifyRow(nonZeroRow, out);
				}
			}
			else {
				subtractRow(currRow, nonZeroRow, currElement.getNum(), out);
			}
			currRow++;
		}
		currCol++;
	}



}

void Matrix::subtractRow(int row1, int row2, int mult, std::ostream& out) {
	for (int i = 0; i < mvVectors.at(row1).size(); i++) {
		Rational newRational(0, 0);
		newRational = Rational(mult, 1) * mvVectors.at(row2).getElement(i);
		mvVectors.at(row1).getElement(i) -= newRational;
	}
	out << "R" << row1 + 1 << " = " << "R" << row1 + 1 << " - " << mult << "R" << row2 + 1;
	out << std::endl;
	print(out);
	out << std::endl;
}

//***************************************************************************
//Function:    simplifyRow
//
//Description: simplifies the given row in the matrix
//
//Parameters:	 row - an int containing the row to simplify
//						 out - the stream to print the operation to
//
//Returned:    Rational - the rational used as a row operation
//***************************************************************************
void Matrix::simplifyRow(int row, std::ostream& out) {
	Rational inverse(0, 0);
	inverse = mvVectors.at(row).simplify();
	if (inverse.getNum() != inverse.getDen()) {
		out << "R" << row + 1 << " = " << inverse << "R" << row + 1;
		out << std::endl;
		print(out);
		out << std::endl;
	}
}

