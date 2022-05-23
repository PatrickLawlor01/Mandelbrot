#include "zmatrix.h"
#include "consts.h"

ZMatrix::ZMatrix() {

	plane = new Complex[ARR_SIZE];
	counts = new int[ARR_SIZE];

	//for (int i = 0; i < ZMatrix::ARR_SIZE; i++) {
	//	
	//	plane[i].re = 0;
	//	plane[i].im = 0;
	//	
	//}
}

ZMatrix::~ZMatrix() {
	delete[] plane;
}

Complex& ZMatrix::getElement(int i) {
	return this->plane[i];
}

void ZMatrix::setElement(int i, double _re, double _im) {
	this->plane[i].re = _re;
	this->plane[i].im = _im;
}

int ZMatrix::getCount(int i) {
	return this->counts[i];
}

void ZMatrix::setCount(int i, int count) {
	this->counts[i] = count;
}

int ZMatrix::getX(int i) {
	return i % SIZE_X;
}


int ZMatrix::getY(int i) {
	return i / SIZE_X;
}


int ZMatrix::getIndex(int x, int y) {
	return ((y - 1) * SIZE_X) + x;
}

