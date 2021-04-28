#include <iostream>
#include "Vector.h"
#include "Matrix.h"

//***************************************************************************
//Function:    main
//
//Description: Main driver for the calculator program
//
//Parameters:	 None
//
//Returned:    int -	Exit Status
//***************************************************************************
int main() {
	const std::string CONTINUE = "Y";
	int numRows;
	std::string selection = CONTINUE;

	while (selection == CONTINUE) {
		Matrix theMatrix;

		system("cls");
		std::cout << "******************************\n";
		std::cout << "Reduced Row Echelon Calculator\n";
		std::cout << "******************************\n\n";

		std::cout << "Enter the number of rows: ";
		std::cin >> numRows;
		std::cout << std::endl;
		std::cin.ignore();

		for (int i = 0; i < numRows; i++) {
			Vector newVector;
			std::cout << "Enter row " << i + 1 << ": ";
			std::cin >> newVector;
			theMatrix.addVector(newVector);
		}

		std::cout << std::endl;
		theMatrix.reduce(std::cout);

		std::cout << "\n\nAnother? (Y/N): ";
		std::cin >> selection;
	}

	return EXIT_SUCCESS;
}