#pragma once
#include "complex.h"

// data structure of variables of Complex type 
// underlying storage is 1d array, with functions to switch between array and 2d coordinates for grid size (SIZE_X, SIZE_Y)
// also contains an int array of same size to track iteration cutoff for each point

class ZMatrix {

	Complex* plane;
	int* counts;

public:

	ZMatrix();
	~ZMatrix();

	Complex& getElement(int i);
	void setElement(int i, long double _re, long double _im);

	int getCount(int i);
	void setCount(int i, int count);

	int getX(int i);
	int getY(int i);
	int getIndex(int x, int y);

};