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
	int numCols = mvVectors[0].size(), numRows = mvVectors.size();
	int pivotRow, numPivots = 0;
	Rational currElement(0, 0), pivotElement(0, 0);

	print(out);

	for (int i = 0; i < numCols; i++) {
		for (int j = numPivots; j < numRows; j++) {
			pivotElement = mvVectors[j].getElement(i);
			if (!pivotElement.isZero()) {
				pivotRow = j;
				simplifyRow(pivotRow, out);
				for (int k = 0; k < numRows; k++) {
					currElement = mvVectors[k].getElement(i);
					if (k != pivotRow && !currElement.isZero()) {
						subtractRow(k, pivotRow, currElement, out);
					}
				}
				numPivots++;
				j = numRows;
			}
		}
	}
}

//***************************************************************************
//Function:    subtractRow
//
//Description: subtracts a row from another row
//
//Parameters:	 rRow  - the index of the vector to subtract from
//						 pRow  - the index of the vector to subtract
//						 rat   - a rational containing how many of row2 to subtract
//						 out   - the ostream to print the operation to
//
//Returned:    None
//***************************************************************************
void Matrix::subtractRow(int rRow, int pRow, Rational rat,
												 std::ostream& out) {
	for (int i = 0; i < mvVectors.at(rRow).size(); i++) {
		mvVectors.at(rRow).getElement(i) -= rat * mvVectors.at(pRow).getElement(i);
	}
	out << std::endl << "R" << rRow + 1 << " = " << "R" << rRow + 1
			<< " - " << rat << "R" << pRow + 1 << std::endl << std::endl;
	print(out);
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
		out << std::endl << "R" << row + 1 << " = " << inverse << "R" << row + 1;
		out << std::endl;
		print(out);
		out << std::endl << std::endl;
	}
}

