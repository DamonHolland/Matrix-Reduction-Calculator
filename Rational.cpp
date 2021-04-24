#include "Rational.h"

//***************************************************************************
//Constructor: Rational
//
//Description: Default Constructor for rational. Initializes numerator to 0
//						 and denominator to 1
//
//Parameters:	 None
//
//Returned:    None
//***************************************************************************
Rational::Rational() {
	mNumerator = 0;
	mDenominator = 1;
}

//***************************************************************************
//Constructor: Rational
//
//Description: Creates a rational with the given numerator and denominator
//
//Parameters:	 num - the int numerator
//						 den - the int denominator
//
//Returned:    None
//***************************************************************************
Rational::Rational(int num, int den) {
	mNumerator = num;
	mDenominator = den;
}

//***************************************************************************
//Function:    getNum
//
//Description: Returns the numerator
//
//Parameters:	 None
//
//Returned:    int - the numerator
//***************************************************************************
int Rational::getNum() { return mNumerator; }

//***************************************************************************
//Function:    getDen
//
//Description: Returns the denominator
//
//Parameters:	 None
//
//Returned:    int - the denominator
//***************************************************************************
int Rational::getDen() { return mDenominator; }

//***************************************************************************
//Function:    reduce
//
//Description: Reduces the rational
//
//Parameters:	 None
//
//Returned:    None
//***************************************************************************
void Rational::reduce() {
	int GCD = 1;
	int max = (abs(mNumerator) > abs(mDenominator)) ? abs(mNumerator)
																									: abs(mDenominator);

	for (int i = 1; i <= max; i++) {
		if (mNumerator % i == 0 && mDenominator % i == 0) { GCD = i; }
	}
		
	mNumerator /= GCD;
	mDenominator /= GCD;

	if (mDenominator < 0) {
		mDenominator = 0 - mDenominator;
		mNumerator = 0 - mNumerator;
	}
}

//***************************************************************************
//Function:    isZero
//
//Description: Returns if the value of the rational is 0
//
//Parameters:	 None
//
//Returned:    bool - if the rational is equal to 0
//***************************************************************************
bool Rational::isZero() {
	return (mNumerator == 0 || mDenominator == 0);
}

//***************************************************************************
//Function:    getInverse
//
//Description: Returns the inverse of this Rational
//
//Parameters:	 None
//
//Returned:    Rational - the inverse
//***************************************************************************
Rational Rational::getInverse() {
	return Rational(mDenominator, mNumerator);
}

//***************************************************************************
//Function:    operator=
//
//Description: Sets this Rational to another
//
//Parameters:	 rat       - the other rational
//
//Returned:    Rational& - the new rational
//***************************************************************************
Rational& Rational::operator=(const Rational& rat) {
	mNumerator = rat.mNumerator;
	mDenominator = rat.mDenominator;
	return *this;
}

//***************************************************************************
//Function:    operator+=
//
//Description: Adds another rational to self
//
//Parameters:	 rat       - the other rational
//
//Returned:    Rational& - the new rational
//***************************************************************************
Rational& Rational::operator+=(const Rational& rat) {
	*this = *this + rat;
	return *this;
}

//***************************************************************************
//Function:    operator-=
//
//Description: Subtracts another rational from self
//
//Parameters:	 rat       - the other rational
//
//Returned:    Rational& - the new rational
//***************************************************************************
Rational& Rational::operator-=(const Rational& rat) {
	*this = *this - rat;
	return *this;
}

//***************************************************************************
//Function:    operator*=
//
//Description: Multiplies self by another rational
//
//Parameters:	 rat       - the other rational
//
//Returned:    Rational& - the new rational
//***************************************************************************
Rational& Rational::operator*=(const Rational& rat) {
	*this = *this * rat;
	return *this;
}

//***************************************************************************
//Function:    operator/=
//
//Description: Divides self by another rational
//
//Parameters:	 rat       - the other rational
//
//Returned:    Rational& - the new rational
//***************************************************************************
Rational& Rational::operator/=(const Rational& rat) {
	*this = *this / rat;
	return *this;
}

//***************************************************************************
//Function:    operator+
//
//Description: Adds Rationals
//
//Parameters:	 rat      - the other rational
//
//Returned:    Rational - the new rational
//***************************************************************************
Rational Rational::operator+(const Rational& rat) {
	int num = mNumerator * rat.mDenominator + rat.mNumerator + mDenominator;
	int den = mDenominator * rat.mDenominator;
	Rational newRat(num, den);
	newRat.reduce();
	return newRat;
}

//***************************************************************************
//Function:    operator-
//
//Description: Subtracts Rationals
//
//Parameters:	 rat      - the other rational
//
//Returned:    Rational - the new rational
//***************************************************************************
Rational Rational::operator-(const Rational& rat) { 
	int num = mNumerator * rat.mDenominator - rat.mNumerator * mDenominator;
	int den = mDenominator * rat.mDenominator;
	Rational newRat(num, den);
	newRat.reduce();
	return newRat;
}

//***************************************************************************
//Function:    operator*
//
//Description: Multiplies Rationals
//
//Parameters:	 rat      - the other rational
//
//Returned:    Rational - the new rational
//***************************************************************************
Rational Rational::operator*(const Rational& rat) {
	Rational newRat(mNumerator * rat.mNumerator,
									mDenominator * rat.mDenominator);
	newRat.reduce();
	return newRat;
}

//***************************************************************************
//Function:    operator/
//
//Description: Divides Rationals
//
//Parameters:	 rat      - the other rational
//
//Returned:    Rational - the new rational
//***************************************************************************
Rational Rational::operator/(const Rational& rat) {
	Rational newRat(mNumerator * rat.mDenominator,
		mDenominator * rat.mNumerator);
	newRat.reduce();
	return newRat;
}

//***************************************************************************
//Function:    operator<<
//
//Description: Prints the rational to the ostream
//
//Parameters:	 os  - the ostream to print to
//						 rat - the rational to print
//
//Returned:    None
//***************************************************************************
std::ostream& operator<<(std::ostream& os, const Rational& rat) {
	os << rat.mNumerator;
	if (rat.mDenominator != 1) { os << "/" << rat.mDenominator; }
	return os;
}

//***************************************************************************
//Function:    operator>>
//
//Description: Reads a rational from the istream
//
//Parameters:	 is  - the istream to read from
//						 rat - the rational to read into
//
//Returned:    None
//***************************************************************************
std::istream& operator>>(std::istream& is, Rational& rat) {
	is >> rat.mNumerator;
	return is;
}