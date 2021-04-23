#pragma once
#include <vector>
#include <iostream>
#include "Rational.h"

class Vector
{
public:
	void addElement(int element);
	void print(std::ostream& out);
	Rational simplify();

	friend std::istream& operator>>(std::istream& in, Vector& vector);

private:
	std::vector<Rational> mvElements;
};

