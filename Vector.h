#pragma once
#include <vector>
#include <iostream>

class Vector
{
public:
	void addElement(double element);
	void print(std::ostream& out);
	int simplify();

	friend std::istream& operator>>(std::istream& in, Vector& vector);

private:
	std::vector<double> mvElements;
};

