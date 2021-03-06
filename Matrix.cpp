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
	if (numRows() > 0 && vector.size() != numCols()) {
		std::cout << "\nInvalid vector, number of columns does not match.\n";
		exit(EXIT_FAILURE);
	}
	else {
		mvVectors.push_back(vector);
	}
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
	std::vector<int> vColWidths = getColWidths();
	for (int i = 0; i < numRows(); i++) {
		mvVectors.at(i).print(out, vColWidths);
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
	int numPivots = 0;
	print(out);
	for (int i = 0; i < numCols(); i++) {
		for (int j = numPivots; j < numRows(); j++) {
			if (!mvVectors[j].getElement(i).isZero()) {
				simplifyRow(j, out);
				for (int k = 0; k < numRows(); k++) {
					if (k != j && !mvVectors[k].getElement(i).isZero())
						subtractRow(k, j, mvVectors[k].getElement(i), out);
				}
				swapRows(numPivots++, j, out);
				j = numRows();
			}
		}
	}
}

//***************************************************************************
//Function:    numRows
//
//Description: Returns the number of rows in the matrix
//
//Parameters:	 None
//
//Returned:    int - an integer containing the number of rows
//***************************************************************************
int Matrix::numRows() {
	return (int) mvVectors.size();
}

//***************************************************************************
//Function:    numCols
//
//Description: Returns the number of columns in the matrix
//
//Parameters:	 None
//
//Returned:    int - an integer containing the number of columns
//***************************************************************************
int Matrix::numCols() {
	return (int)mvVectors[0].size();
}

//***************************************************************************
//Function:    swapRows
//
//Description: swaps two rows in the matrix
//
//Parameters:	 row1  - the index of the first vector to swap
//						 row2  - the index of the second vector to swap
//						 out   - the ostream to print the operation to
//
//Returned:    None
//***************************************************************************
void Matrix::swapRows(int row1, int row2, std::ostream& out) {
	if (row1 == row2) { return; }
	Vector temp = mvVectors[row1];
	mvVectors[row1] = mvVectors[row2];
	mvVectors[row2] = temp;
	out << "\nR" << row1 + 1 << " <-> " << "R" << row2 + 1 << "\n\n";
	print(out);
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
	for (int i = 0; i < numCols(); i++) {
		mvVectors[rRow].getElement(i) -= rat * mvVectors[pRow].getElement(i);
	}
	out << "\nR" << rRow + 1 << " = " << "R" << rRow + 1
			<< " - " << rat << "R" << pRow + 1 << "\n\n";
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
	Rational inverse = mvVectors.at(row).simplify();
	if (inverse.getNum() != inverse.getDen()) {
		out << "\nR" << row + 1 << " = " << inverse << "R" << row + 1 << "\n\n";
		print(out);
	}
}

//***************************************************************************
//Function:    getColWidths
//
//Description: returns a vector containing the max digit length in each
//						 column. Helps to get widths for printing
//
//Parameters:	 None
//
//Returned:    vector<int> - a vector containing the max digit lengths
//***************************************************************************
std::vector<int> Matrix::getColWidths() {
	std::vector<int> vcolWidths;

	for (int i = 0; i < numCols(); i++) {
		int max = 0;
		for (int j = 0; j < numRows(); j++) {
			if (mvVectors[j].getElement(i).digitWidth() > max) {
				max = mvVectors[j].getElement(i).digitWidth();
			}
		}
		vcolWidths.push_back(max);
	}

	return vcolWidths;
}