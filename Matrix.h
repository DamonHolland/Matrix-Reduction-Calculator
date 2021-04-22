#pragma once
#include "Vector.h"

class Matrix
{
	public:
		void addVector(Vector vector);
		void print(std::ostream& out);
		void simplifyRows(std::ostream& out);

	private:
		int simplifyRow(int row);
		std::vector<Vector> mvVectors;
};

