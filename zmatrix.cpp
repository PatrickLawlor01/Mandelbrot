#include "zmatrix.h"
#include "consts.h"

ZMatrix::ZMatrix() {

	plane = new Complex[ARR_SIZE];	// store complex numbers z in view
	counts = new int[ARR_SIZE];		// store iteration cutoff points for each z

}


ZMatrix::~ZMatrix() {
	delete[] plane;
	delete[] counts;
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


// convert index into x coordinate
int ZMatrix::getX(int i) {
	return i % SIZE_X;
}


// convert index into y coordinate
int ZMatrix::getY(int i) {
	return i / SIZE_X;
}


// convert x and y coordinate into index
int ZMatrix::getIndex(int x, int y) {
	return (y  * SIZE_X) + x;
}

