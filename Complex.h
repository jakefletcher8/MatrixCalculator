#pragma once
#include <iostream>
#include <math.h>
#include "Constants.h"

struct Complex {

	double real;
	double imaginary;

	Complex operator+(const Complex& input) {

		return { this->real + input.real, this->imaginary + input.imaginary };

	}

	Complex operator+(const double& input) {

		return { this->real + input, this->imaginary};

	}

	Complex operator-(const Complex& input) {

		return { this->real - input.real, this->imaginary - input.imaginary };

	}

	Complex operator-(const double& input) {

		return { this->real - input, this->imaginary };

	}

	Complex operator*(const Complex& input) {

		return { this->real * input.real - this->imaginary * input.imaginary, this->imaginary * input.real + this->real * input.imaginary };

	}

	Complex operator*(const double& input) {

		return { this->real *input, this->imaginary *input};

	}

	Complex operator/(const Complex& input) {

		return { (this->real * input.real + this->imaginary * input.imaginary) / ((input.real * input.real) + (input.imaginary * input.imaginary)),(input.real * this->imaginary - this->real * input.imaginary) / ((input.real * input.real) + (input.imaginary * input.imaginary)) };

	}

	Complex operator/(const double& input) {

		return { this->real / input, this->imaginary / input };
	
	}
	

};

inline Complex operator"" _i(long double input) {
	return { 0.0, static_cast<double>(input) };
}

inline Complex operator"" _i(unsigned long long input) {
	return { 0.0, static_cast<double>(input) };
}

inline Complex operator+(double real_val, const Complex& complex_val) {
	return { real_val + complex_val.real, complex_val.imaginary };
}

inline Complex operator-(double real_val, const Complex& complex_val) {
	return { real_val - complex_val.real, complex_val.imaginary };
}

inline Complex complexConjugate(const Complex& input) {

	return { input.real, -1 * input.imaginary };

}

inline void printComplexNumber(const Complex& input) {

	std::cout << "Number - " << input.real << " + " << input.imaginary << "i" << std::endl;


}

inline void printComplexNumberRect(const Complex& input) {

	std::cout << "Number - " << input.real << " + " << input.imaginary << "i" << std::endl;


}

inline void printComplexNumberRect(const double& input) {

	std::cout << "Number - " << input << " +  0i" << std::endl;
	

}

inline void printComplexNumberPolar(const Complex& input) {

	double radians = atan2(input.imaginary, input.real);

	std::cout << "Number - " << std::pow((std::pow(input.real,2)+std::pow(input.imaginary,2)),0.5) << " at angle - " << radians << " radians / " << radians*180/PI << " degrees..." << std::endl;


}

