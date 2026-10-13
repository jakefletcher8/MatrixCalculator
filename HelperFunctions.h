#pragma once
#include "Matrix.h"
#include <iostream>

void printValues(Matrix input) {

	std::cout << "Columns - " << input.returnColumns() << "\n";
	std::cout << "Rows - " << input.returnRows() << "\n";
	std::cout << "Is Square - " << input.returnIsSquare() << "\n";
	std::cout << "\n";

	return;

}
void printMatrix(Matrix input) {



	for (int row = 0; row < input.returnRows(); row++) {

		std::cout << "[ ";

		for (int column = 0; column < input.returnColumns(); column++) {

			std::cout << input.returnValue(row, column) << " ";

		}

		std::cout << "]\n";

	}
	std::cout << "\n \n";
}