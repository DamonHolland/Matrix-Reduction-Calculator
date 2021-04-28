#pragma once
#include <iostream>

class Rational
{
public:
	Rational();
	Rational(int, int);
	int getNum();
	int getDen();
	int digitWidth();
	Rational getInverse();
	void reduce();
	bool isZero();
	Rational& operator=(const Rational& rat);
	Rational& operator+=(const Rational& rat);
	Rational& operator-=(const Rational& rat);
	Rational& operator/=(const Rational& rat);
	Rational& operator*=(const Rational& rat);
	Rational operator+(const Rational& rat);
	Rational operator-(const Rational& rat);
	Rational operator/(const Rational& rat);
	Rational operator*(const Rational& rat);
	friend std::ostream& operator<<(std::ostream& os, const Rational& dt);
	friend std::istream& operator>>(std::istream& os, Rational& dt);

private:
	int mNumerator = 0;
	int mDenominator = 1;
};

