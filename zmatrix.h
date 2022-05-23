#pragma once
#include "complex.h"

class ZMatrix {

	Complex* plane;
	int* counts;

public:



	ZMatrix();
	~ZMatrix();

	Complex& getElement(int i);
	void setElement(int i, double _re, double _im);

	int getCount(int i);
	void setCount(int i, int count);

	int getX(int i);
	int getY(int i);
	int getIndex(int x, int y);

};