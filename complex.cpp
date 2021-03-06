#include "complex.h"
#include <sstream>
#include <string>
#include <QtCore/qtextstream.h>
#include <cmath>

// for writing to std::cout
std::ostream& operator<<(std::ostream& os, const Complex& c) {
	if (c.im >= 0) {
		os << c.re << "+" << c.im << "i";
	}
	else {
		os << c.re << c.im << "i";
	}
	return os;
}


Complex::Complex(long double _re, long double _im) {

	re = _re;
	im = _im;

}


Complex::Complex() {
	re = 0;
	im = 0;
}


Complex Complex::operator+(const Complex& rhs) {
	return Complex(this->re + rhs.re, this->im + rhs.im);
}


Complex Complex::operator+(double real_rhs) {
	Complex c = Complex(real_rhs, 0);
	return *this + c;
}


Complex Complex::operator*(const Complex& rhs) {
	return Complex((this->re * rhs.re) - (this->im * rhs.im), (this->re * rhs.im) + (this->im * rhs.re));
}


Complex Complex::operator*(double real_rhs) {
	Complex c = Complex(real_rhs, 0);
	return *this * c;
}


Complex& Complex::operator*=(const Complex& rhs) {
	long double re1 = this->re;
	long double im1 = this->im;
	long double re2 = rhs.re;
	long double im2 = rhs.im;
	this->re = (re1 * re2) - (im1 * im2);
	this->im = (re1 * im2) + (im1 * re2);
	return *this;
}


Complex& Complex::operator*=(double real_rhs) {
	Complex c = Complex(real_rhs, 0);
	*this *= c;
	return *this;
}


Complex& Complex::operator+=(const Complex& rhs) {
	this->re += rhs.re;
	this->im += rhs.im;
	return *this;
}


// for converting to string in form a+bi
std::string Complex::toString()
{
	std::stringstream ss("");
	if (this->re != 0) ss << this->re;
	if (this->im != 0) {
		if (this->im > 0) ss << "+";
		ss << this->im;
		ss << "i";
	}
	if (this->re == 0 || this->im == 0) ss << "0";
	return ss.str();
}

// return magnitude of z
double Complex::abs() {
	return std::sqrt(std::pow(re, 2) + std::pow(im, 2));
}

