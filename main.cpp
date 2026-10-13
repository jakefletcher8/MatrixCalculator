#include <iostream>
#include "Matrix.h"
#include "HelperFunctions.h"
#include "Complex.h"


int main() {

	Matrix test(2, 3);
	Matrix test2(3, 2);

	test.fillCommandLine();
	test2.fillCommandLine();

	printMatrix(test);
	printMatrix(test2);

	printMatrix(test*test2);

	return 0;

}