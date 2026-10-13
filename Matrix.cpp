#include "Matrix.h"


Matrix::Matrix(int rows, int columns) {

	//Set row and column count
	//Store bool variable to determine if matrix is square

	this->columnCount = columns;
	this->rowCount = rows;
	this->isSquare = (columns == rows);

	//initialise empty and then fill with values

	for (int row = 0; row < rows; row++) {

		std::vector<float> column(columns, 0);
		this->values.push_back(column);

	}

}

Matrix::~Matrix() {



}

//Overwrite currently stored values with new values

void Matrix::setValues(std::vector<std::vector<float>> update) {

	this->values = update;

}

//Return column count

int Matrix::returnColumns() {

	return columnCount;

}

//Return row count

int Matrix::returnRows() {

	return rowCount;

}

//Return boolean value for if the matrix is square or not

bool Matrix::returnIsSquare() {

	return isSquare;

}

//return a value at a given row and column

float Matrix::returnValue(int row, int column) {

	return (values.at(row)).at(column);

}

//Find the determinant of any square matrix

float Matrix::returnDeterminant() {
	
	//If the matrix has been reduced to or is 1x1 just return the only value

	if ((rowCount == columnCount) && (rowCount != 0)) {

		if (rowCount == 1) {

			return this->values.at(0).at(0);

		}

		//initialise variables to be used

		float determinant = 0;
		bool sign = 1;

		//copy the matrix to allow computation

		Matrix input(rowCount, columnCount);
		input.setValues(this->values);

		//iterate through all of the columns to use the coefficients stored in row 0

		for (int column = 0; column < columnCount; column++) {

			//Create a resultant square matrix for each coefficient in row 0 with an order of the current square matrix minus 1

			Matrix resultant(input.returnRows() - 1, input.returnColumns() - 1);

			//Create variables that will allow for indexing of the resultant matrix

			int newRow = 0, newColumn = 0;

			//Iterate through every cell in the matrix

			for (int resultRow = 1; resultRow < input.returnRows(); resultRow++) {
				for (int resultColumn = 0; resultColumn < input.returnColumns(); resultColumn++) {

					//If the current cell is in the chosen column then skip and do not increment the column indexing variable

					if ((resultColumn == column) || (resultRow == 0)) {

						continue;

					}

					//If the column indexing variable exceeds the resultant matrix then reset the column increment and increment the row indexing variable, (start same process from next row)

					if (newColumn == (resultant.returnRows())) {
					
						//print stuff for debug
						
						std::cout << "\n";
						newColumn = 0;
						newRow++;

					}
					
					//The indexed cell in the resultant matrix is equal to the selected cell in the original matrix

						resultant.values.at(newRow).at(newColumn) = input.returnValue(resultRow, resultColumn);
						
						//print it for debug 
						
						std::cout << resultant.values.at(newRow).at(newColumn) << "   ";
						newColumn++;
					


				}
			}

			//print stuff for debug

			std::cout << "\n";

			//Add the determinant of the resultant matrix * the coefficient in row 0 * boolean value to alternate between positive and negative magnitude
			//add this to running sum of determinant

				determinant += (input.values.at(0).at(column) * (-1 + 2*sign) * resultant.returnDeterminant());
				
				//print determinant for debug purpose
								
				std::cout << determinant << std::endl << std::endl;
				
				//flip sign to alternate addition and subtraction
				
				sign = !sign;
		}
		
		//return the final result once it has been iterated through fully 

		return determinant;

	}

	//if the matrix is not square then return an error (0 for now)

	else {

		return 0;

	}

	//return 0 if the function somehow reaches here

	return 0;

}

Matrix Matrix::operator+(const Matrix& input) {

	if ((this->columnCount != input.columnCount) || (this->rowCount != input.rowCount)) {

		return input;

	}
	
	Matrix result(rowCount, columnCount);

	for (int row = 0; row < this->rowCount; row++) {
		for (int column = 0; column < columnCount; column++) {

			result.values.at(row).at(column) = this->values.at(row).at(column) + input.values.at(row).at(column);

		}
	}

	return result;

}

Matrix Matrix::operator-(const Matrix& input) {

	if ((this->columnCount != input.columnCount) || (this->rowCount != input.rowCount)) {

		return input;

	}

	Matrix result(rowCount, columnCount);

	for (int row = 0; row < this->rowCount; row++) {
		for (int column = 0; column < columnCount; column++) {

			result.values.at(row).at(column) = this->values.at(row).at(column) - input.values.at(row).at(column);

		}
	}

	return result;

}

Matrix Matrix::operator*(const Matrix& input) {

	if ((this->columnCount != input.rowCount)) {

		return input;

	}

	Matrix result(rowCount, input.columnCount);

	for (int row = 0; row < result.rowCount; row++) {
		for (int column = 0; column < result.columnCount; column++) {

			for (int rowMult = 0; rowMult < this->columnCount; rowMult++) {
	
					result.values.at(row).at(column) += (this->values.at(row).at(rowMult) * input.values.at(rowMult).at(column));
				
			}
		}
	}

	return result;

}

Matrix Matrix::operator/(const Matrix& input) {
	/*
	
	need to use the determinant function to achieve matrix division

	*/

	return input;
}

Matrix Matrix::SquareMatrix() {

	Matrix result(rowCount, columnCount);

	result.setValues(this->values);

	if (this->isSquare != true) {

		return result;

	}

	return result * result;


}

void Matrix::fillRand() {

	for (int row = 0; row < rowCount; row++) {
		for (int column = 0; column < columnCount; column++) {

			values.at(row).at(column) = -20 + (rand() % (20 + 20 + 1));

		}


	}


}

void Matrix::fillCommandLine() {

	for (int row = 0; row < rowCount; row++) {
		for (int column = 0; column < columnCount; column++) {

			for (int row2 = 0; row2 < rowCount; row2++) {

				std::cout << "[ ";

				for (int column2 = 0; column2 < columnCount; column2++) {

					std::cout << values.at(row2).at(column2) << " ";

				}

				std::cout << "]\n";

			}
			std::cout << "\n \n";


			std::cout << "Row - " << row << ", Column - " << column << ": \n";
			double input;
			
			std::cin >> input;

			clearTerminal();

			values.at(row).at(column) = input;

		}


	}

}