#pragma once
#include "Vector.h"

class Matrix
{
	public:
		void addVector(Vector vector);
		void print(std::ostream& out);
		void reduce(std::ostream& out);
		
	private:
		void simplifyRow(int row, std::ostream&);
		void swapRows(int row1, int row2, std::ostream& out);
		void subtractRow(int rRow, int pRow, Rational inv, std::ostream& out);
		int numRows();
		int numCols();
		std::vector<int> getColWidths();
		std::vector<Vector> mvVectors;
};

