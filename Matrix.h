#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include "TerminalFunctions.h"

/*TO DO :
	
	-Implement returnDeterminant() function
	-Finish division operator overload


*/

class Matrix {

public:

	Matrix(int rows, int columns);
	~Matrix();
	void setValues(std::vector<std::vector<float>> update);
	int returnRows();
	int returnColumns();
	bool returnIsSquare();
	float returnValue(int row, int column);
	void fillRand();
	void fillCommandLine();
	float returnDeterminant();

	Matrix operator+(const Matrix& input);
	Matrix operator-(const Matrix& input);
	Matrix operator*(const Matrix& input);
	Matrix operator/(const Matrix& input);
	Matrix SquareMatrix();

private:

	std::vector<std::vector<float>> values;
	int columnCount;
	int rowCount;
	bool isSquare;

};

#endif 