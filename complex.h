#pragma once
#include <iostream>
#include <string>



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
	Complex(double _re, double _im);

	double abs();
	

};
