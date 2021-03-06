#pragma once
#include <iostream>
#include <string>

// class to handle complex numbers & arithmentic

class Complex {

	std::string output;

public:

	friend std::ostream& operator<<(std::ostream& os, const Complex& c);

	std::string toString();

	Complex operator+(const Complex& rhs);
	Complex operator+(double real_rhs);
	Complex operator*(const Complex& rhs);
	Complex operator*(double real_rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(double real_rhs);
	Complex& operator+=(const Complex& rhs);

	double re{0}, im{0};

	Complex();
	Complex(long double _re, long double _im);

	double abs();
	

};
