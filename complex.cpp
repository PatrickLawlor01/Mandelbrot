#include "complex.h"
#include <sstream>
#include <string>
#include <QtCore/qtextstream.h>
#include <cmath>

std::ostream& operator<<(std::ostream& os, const Complex& c) {
	if (c.im >= 0) {
		os << c.re << "+" << c.im << "i";
	}
	else {
		os << c.re << c.im << "i";
	}
	return os;
}



Complex::Complex(double _re, double _im) {

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
	double re1 = this->re;
	double im1 = this->im;
	double re2 = rhs.re;
	double im2 = rhs.im;
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

double Complex::abs() {
	return std::sqrt(std::pow(re, 2) + std::pow(im, 2));
}

