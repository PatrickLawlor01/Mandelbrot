#include "complex.h"
#include <sstream>
#include <string>
#include <QtCore/qtextstream.h>

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
	this->re = (this->re * rhs.re) - (this->im * rhs.im);
	this->im = (this->re * rhs.im) + (this->im * rhs.re);
	return *this;
}

Complex& Complex::operator*=(double real_rhs) {
	Complex c = Complex(real_rhs, 0);
	*this *= c;
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

