#pragma once
#include <vector>
#include <iostream>
#include "Rational.h"

class Vector
{
public:
	void addElement(int element);
	void print(std::ostream& out, std::vector<int> vWidths);
	int size();
	Rational& getElement(int index);
	Rational simplify();

	friend std::istream& operator>>(std::istream& in, Vector& vector);

private:
	std::vector<Rational> mvElements;
};

