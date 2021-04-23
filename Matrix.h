#pragma once
#include "Vector.h"

class Matrix
{
	public:
		void addVector(Vector vector);
		void print(std::ostream& out);
		void reduce(std::ostream& out);
		void subtractRow(int row1, int row2, int mult, std::ostream& out);

	private:
		void simplifyRow(int row, std::ostream&);
		std::vector<Vector> mvVectors;
};

